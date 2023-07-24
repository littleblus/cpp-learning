#include <iostream>
#include "stack_queue.h"
using namespace std;

void testStack() {
	blus::stack<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!q.empty()) {
		cout << q.top() << ' ';
		q.pop();
	}
	cout << endl;
}

void testQueue() {
	blus::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}
	cout << endl;
}