#include "thread.hpp"
#include <unistd.h>
#include <iostream>
#include <vector>

using namespace std;

void Print() {
	int i = 3;
	while (i--) {
		printf("haha, 我是一个封装的线程...\n");
		sleep(1);
	}
}

int main() {
	std::vector<Thread> threads;

	for (int i = 0;i < 10; i++) {
		threads.emplace_back(reinterpret_cast<callback_t>(Print));
	}

	for (auto& t : threads) {
		t.create();
	}

	for (auto& t : threads) {
		t.start();
	}


	for (auto& t : threads) {
		t.join();
	}

	return 0;
}