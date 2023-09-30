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
	table.insert({ "ÅÅÐò","xxx" });
	table.insert({ "Æ»¹û","xxx" });
	table.insert({ "Ïã½¶","xxx" });
	table.print();
	auto cur = table.find("ÅÅÐò");
	cur->_val.second = "sort";
	table.print();

	return 0;
}
