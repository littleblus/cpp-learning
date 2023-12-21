#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>
#include <string>
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
    std::string s;
    char* str = static_cast<char*>(shmat(shmid, nullptr, 0));
    if (str == reinterpret_cast<char*>(-1)) {
        std::cout << "shmat error" << std::endl;
        exit(1);
    }
    while (std::cin >> s) {
        strcpy(str, s.c_str());
        if (s == "exit") break;
    }
    shmdt(str);
    return 0;
}