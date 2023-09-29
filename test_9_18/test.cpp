#include <iostream>
#include "hashTable.h"

using namespace std;

struct key {
	int operator()(int key) {
		return key;
	}
};

int main() {
	vector<int> v{ 26,46,23,6,9,13,6,34,798,23,18,19,44,5,78 };
	blus::hashTable<int, int, key> table;
	for (auto e : v) {
		table.insert(e);
	}
	table.print();
	cout << table.erase(26) << endl;
	cout << table.erase(999) << endl;
	table.print();

	return 0;
}
