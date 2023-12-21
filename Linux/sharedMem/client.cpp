#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

int main() {
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    key_t key = ftok(cwd, 919);
    if (key == -1) {
        std::cout << "ftok error" << std::endl;
        exit(1);
    }
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        std::cout << "shmget error" << std::endl;
        exit(1);
    }
    char* str = static_cast<char*>(shmat(shmid, nullptr, 0));
    if (str == reinterpret_cast<char*>(-1)) {
        std::cout << "shmat error" << std::endl;
        exit(1);
    }
    while (true) {
        if (strcmp(str, "exit") == 0) break;
        std::cout << str << std::endl;
        sleep(1);
    }
    return 0;
}