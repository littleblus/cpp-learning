#include <iostream>
#include <list>
#include "myList.h"
using namespace std;

template<typename T>
void printlt(const blus::list<T>& lt) {
	auto it = lt.begin();
	while (it != lt.end()) {
		cout << *it << ' ';
		++it;
	}
	cout << endl;
}

struct A {
	A(int a = 0, int b = 0) 
		: a(a)
		, b(b)
	{}
	int a;
	int b;
};

int main() {
	blus::list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	printlt(lt1);
	cout << lt1.size() << endl;

	lt1.clear();
	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);
	printlt(lt1);
	cout << lt1.size() << endl;

	return 0;
}