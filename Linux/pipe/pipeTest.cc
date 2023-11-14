// 1.考察pipe函数的使用， 以及对pipe函数参数的理解，同时考察对文件描述符的理解
// 2.要求：先创建管道， 进而创建子进程， 父子进程使用管道进行通信
// 父进程向管道当中写“i am father”，
// 子进程从管道当中读出内容, 并且打印到标准输出
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string>

using namespace std;

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        cout << "pipe error" << endl;
        exit(1);
    }

    int pid = fork();
    if (pid == -1) {
        cout << "fork error" << endl;
        exit(1);
    }
    if (pid) {
        // 父进程
        // 写入，关闭读端
        close(pipefd[0]);
        // 写入
        string str = "i am father";
        write(pipefd[1], str.c_str(), str.size() + 1);
        // 关闭写端
        close(pipefd[1]);
    }
    else {
        // 子进程
        // 读取，关闭写端
        close(pipefd[1]);
        // 读取
        char buf[1024];
        read(pipefd[0], buf, sizeof(buf));
        cout << buf << endl;
        // 关闭读端
        close(pipefd[0]);
    }
    wait(NULL);

    return 0;
}