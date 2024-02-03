#include "skipList.hpp"
#include <iostream>

using namespace std;

void test_slset() {
	//	for(int i = 0; i < 20; i++) {
//		cout << PERCENT_RAND(RAND_GENERATOR) << endl;
//	}
	SLset<int> sl;
	// false true true false
	sl.insert(1);
	sl.insert(2);
	sl.insert(3);
	cout << (sl.count(0) ? "true" : "false") << endl;
	sl.insert(4);
	cout << (sl.count(1) ? "true" : "false") << endl;
	// sl.debugPrint();
	// cout << endl << endl;
	sl.insert(5);
	// sl.debugPrint();
	// cout << endl << endl;
	cout << (sl.count(3) ? "true" : "false") << endl;
	cout << (sl.count(6) ? "true" : "false") << endl;
}

void test_slmap() {
	SLmap<int, int> sl;
	sl[1] = 1;
	sl[2] = 2;
	sl[3] = 3;
	cout << (sl.count(0) ? "true" : "false") << endl;
	for(auto& [x, y] : sl) {
		cout << x << " " << y << endl;
	}
	sl[4] = 4;
	sl[-100] = 100;
	sl[-200] = 200;
	sl.erase(3);
	cout << (sl.count(3) ? "true" : "false") << endl;
	for(auto& [x, y] : sl) {
		cout << x << " " << y << endl;
	}
	cout << sl.size() << endl;

	const SLmap<int, int> csl(sl);
	for(auto& [x, y] : csl) {
		cout << x << " " << y << endl;
	}
}

int main() {
	test_slset();
	test_slmap();
	return 0;
}
