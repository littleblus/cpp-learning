#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>

int main() {
    int fd = open("pipe", O_RDONLY);
    if (fd == -1) {
        std::cout << "pipe is not exist" << std::endl;
        exit(1);
    }
    char buf[1024];
    while (true) {
        int n = read(fd, buf, sizeof(buf));
        if (n == -1) {
            std::cout << "read error" << std::endl;
            exit(1);
        }
        if (n == 0) {
            std::cout << "write is closed, client closed too!" << std::endl;
            exit(0);
        }
        buf[n] = '\0';
        std::cout << buf << std::endl;
    }
    return 0;
}