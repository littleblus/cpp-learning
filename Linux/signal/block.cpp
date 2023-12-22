#include <signal.h>
#include <iostream>
#include <unistd.h>

using namespace std;

// 阻塞2号和40号信号，进行测试
int main() {
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, 2);
    sigaddset(&set, 40); // 实验证明，阻塞40号信号，但是不会导致程序退出
    sigprocmask(SIG_SETMASK, &set, nullptr);

    while (true) {
        sigset_t pending;
        sigpending(&pending);
        for (int i = 1; i <= 64; ++i) {
            if (sigismember(&pending, i)) {
                cout << "1";
            }
            else {
                cout << "0";
            }
        }
        cout << endl;
        sleep(1);
    }

    return 0;
}