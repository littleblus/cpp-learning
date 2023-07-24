#include <iostream>
#include <vector>
#include "priority_queue.h"
using namespace std;

int main() {
	vector<int> v;
	v.push_back(15);
	v.push_back(24);
	v.push_back(3);
	v.push_back(79);
	v.push_back(57);

	blus::priority_queue<int> pq1(v.begin(), v.end());
	while (!pq1.empty()) {
		cout << pq1.top() << ' ';
		pq1.pop();
	}
	cout << endl;

	blus::priority_queue<int, vector<int>, greater<int>> pq2;
	pq2.push(15);
	pq2.push(24);
	pq2.push(3);
	pq2.push(79);
	pq2.push(57);
	while (!pq2.empty()) {
		cout << pq2.top() << ' ';
		pq2.pop();
	}
	cout << endl;

	return 0;
}