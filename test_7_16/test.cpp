#include <iostream>
#include <list>
#include "myList.h"
using namespace std;

template<typename T>
void printlt(blus::list<T> lt) {
	for (auto e : lt) {
		cout << e << ' ';
	}
	cout << endl;
}

int main() {
	blus::list<int> lt1, lt2;
	lt1.push_back(97);
	lt1.push_back(98);
	lt1.push_front(99);
	lt1.push_back(100);

	printlt(lt1);
	cout << lt1.size() << endl;

	return 0;
}