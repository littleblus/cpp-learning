#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;

int main() {
	// 两个线程交替打印奇偶数
	mutex m;
	condition_variable cv;
	int x = 1;
	bool flag = false;

	thread t1([&] {
		for (int i = 0; i < 10; i++) {
			unique_lock<mutex> lg(m);
			while (flag) cv.wait(lg); // while 防止虚假唤醒

			cout << this_thread::get_id() << " " << x << endl;
			x++;

			flag = true;
			cv.notify_one();
		}
		});

	thread t2([&] {
		for (int i = 0; i < 10; i++) {
			unique_lock<mutex> lg(m);
			// while (!flag) cv.wait(lg);
			// 也可以这样写（等同于while） true时继续执行
			cv.wait(lg, [&] { return flag; });

			cout << this_thread::get_id() << " " << x << endl;
			x++;

			flag = false;
			cv.notify_one();
		}
		});

	t1.join();
	t2.join();

	return 0;
}