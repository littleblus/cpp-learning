#include <iostream>
#include <vector>
#include <string>
#include "myVector.h"

using namespace std;

template<typename T>
void print(blus::vector<T>& v) {
	for (auto e : v) {
		cout << e << ' ';
	}
	cout << endl;
}

void test1() {
	blus::vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	print<int>(v1);

	v2.swap(v1);
	print<int>(v2);
}

void test2() {
	blus::vector<string> vs1, vs2;
	vs1.push_back("111");
	vs1.push_back("222");
	vs1.push_back("333");
	vs1.push_back("444");
	vs1.push_back("555");
	print<string>(vs1);

	vs2 = vs1;
	print<string>(vs2);

}

void test3() {
	blus::vector<int> v(15, 3);
	print<int>(v);
}

int main() {
	test1();
	//cout << sizeof(blus::vector<int>) << endl;

	return 0;
}