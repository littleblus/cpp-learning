#include <signal.h>
#include <iostream>
#include <unistd.h>
#include <cstring>

using namespace std;

void sigcb(int signo) {
    cout << "recv a signal no: " << signo << endl;
}

// signal()函数用于设置信号的处理函数
// sigaction()函数用于设置信号的处理动作
int main() {
    //signal(SIGINT, sigcb);
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = sigcb;
    sigaction(SIGINT, &act, nullptr);

    while (1) {
        cout << "process is running" << endl;
        sleep(1);
    }

    return 0;
}