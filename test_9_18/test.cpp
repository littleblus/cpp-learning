#include <iostream>
#include "hashTable.h"

using namespace std;

struct keyoft {
	string operator()(const pair<const string, string>& key) {
		return key.first;
	}
};

int main() {
	openHash::hashTable<string, pair<const string, string>, keyoft> table;
	table.insert({ "����","xxx" });
	table.insert({ "ƻ��","xxx" });
	table.insert({ "�㽶","xxx" });
	table.print();
	auto cur = table.find("����");
	cur->_val.second = "sort";
	table.print();

	return 0;
}
