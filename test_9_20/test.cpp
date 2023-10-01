#include <iostream>
#include "unorderedMap.h"
#include "unorderedSet.h"

using namespace std;

void test1() {
	blus::unordered_set<int> set;
	set.insert(1);
	set.insert(2);
	set.insert(3);
	set.insert(4);
	set.insert(5);
	set.insert(5);
	set.insert(5);
	set.insert(5);
	set.insert(5);
	for (auto e : set) {
		cout << e << ' ';
	}
	cout << endl;
	set.erase(3);
	for (auto e : set) {
		cout << e << ' ';
	}
}

void test2() {
	blus::unordered_map<int, int> map1;
	map1.insert({ 1,2 });
	map1.insert({ 2,3 });
	map1.insert({ 4,5 });
	auto it = map1.find(4);
	cout << it->first << ':' << it->second << endl;
	blus::unordered_map<string, string> map2;
	map2.insert({ "Ïã½¶", "banana" });
	cout << map2["Ïã½¶"] << endl;
}

void test3() {
	blus::unordered_map<int, int> map;
	srand((unsigned int)time(0));
	const int N = 10000;
	for (int i = 0; i < N; i++) {
		map.insert({ rand() % (N * 10) + i,i });
	}
	cout << map.size() << endl;
	for (auto& e : map) {
		cout << e.first << " : " << e.second << endl;
	}
}

int main() {
	//test1();
	//test2();
	test3();

	return 0;
}