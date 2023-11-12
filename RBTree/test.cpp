#include <iostream>
#include "RBTree.h"
#include "myMap.h"

using namespace std;
using blus::RBTree;
using blus::map;

template<class T>
class koft {
public:
	int operator()(const T& p) {
		return p.first;
	}
};

void test1() {
	RBTree<int, pair<int, int>, 
		koft<pair<int, int>>, less<int>> tree;
	tree.Insert(make_pair(10, 10));
	tree.Insert(make_pair(2, 2));
	tree.Insert(make_pair(5, 5));
	tree.Insert(make_pair(7, 7));
	tree.Insert(make_pair(3, 3));
	tree.Insert(make_pair(2, 2));
	tree.Insert(make_pair(-1, -1));
	tree.Insert(make_pair(13, 13));
	tree.PrintInOrder();
}

void test2() {
	// 测试迭代器
	RBTree<int, pair<int, int>, koft<pair<int, int>>, less<int>> tree;
	tree.Insert(make_pair(10, 10));
	tree.Insert(make_pair(2, 2));
	tree.Insert(make_pair(5, 5));
	tree.Insert(make_pair(7, 7));
	tree.Insert(make_pair(3, 3));
	tree.Insert(make_pair(2, 2));
	tree.Insert(make_pair(-1, -1));
	tree.Insert(make_pair(13, 13));
	for (auto& e : tree) {
		cout << e.first << " ";
		e.first++;
	}
	cout << endl;
	for (auto& e : tree) {
		cout << e.first << " ";
	}
	cout << endl;
	const RBTree<int, pair<int, int>, koft<pair<int, int>>, less<int>> ctree(tree);
	for (auto& e : ctree) {
		cout << e.first << " ";
		//e.first++;
	}
	cout << endl;
	auto it = tree.Find(6);
	if (it != tree.end())
		cout << it->second << endl;
	else
		cout << "nullptr" << endl;
}

void test3() {
	map<int, int> m;
	for (int i = 0; i < 10; i++) {
		m[i] = i + 1;
	}
	for (auto& e : m) {
		cout << e.first << " : " << e.second << endl;
	}
	cout << m.find(5)->second << endl;
}

int main() {
	//test1();
	//test2();
	test3();

	return 0;
}