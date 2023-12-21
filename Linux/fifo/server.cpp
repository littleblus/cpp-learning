#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>

// 考察命令mkfifo或者函数mkfifo创建命名管道
void create_pipe() {
	int p = mkfifo("pipe", 0666);
	if (p == -1) {
		std::cout << "mkfifo error" << std::endl;
		exit(1);
	}
}
int main() {
	int fd = open("pipe", O_WRONLY);
	if (fd == -1) {
		if (errno == ENOENT) {
			create_pipe();
			fd = open("pipe", O_WRONLY);
		}
		else {
			std::cout << "pipe open error" << std::endl;
			exit(1);
		}
	}
	std::string s;
	while (std::cin >> s) {
		if (s == "exit") break;
		int n = write(fd, s.c_str(), s.size());
		if (n == -1) {
			std::cout << "write error" << std::endl;
			exit(1);
		}
	}
	return 0;
}