#include <iostream>
#include <vector>
#include "myVector.h"

using namespace std;

template<typename T>
void print(blus::vector<T>& v) {
	for (auto e : v) {
		cout << e << ' ';
	}
	cout << endl;
}

int main() {
	blus::vector<int> v;
	v.push_back(1);
	print<int>(v);

	v.pop_back();
	print<int>(v);

	return 0;
}