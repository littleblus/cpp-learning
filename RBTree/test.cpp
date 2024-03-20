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
	RBTree<int, pair<int, int>, koft<pair<int, int>>, less<int>> tree;
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

void test4() {
	map<int, int> m;
	for (int i = 0; i < 100; i++) {
		m[i] = i + 1;
	}
	m.erase(33);
	for (auto& e : m) {
		cout << e.first << " : " << e.second << endl;
	}
	cout << endl;
	m.erase(88);
	for (auto& e : m) {
		cout << e.first << " : " << e.second << endl;
	}
	cout << endl;
	for (int i = 35; i < 55; i++) {
		m.erase(i);
	}
	for (auto& e : m) {
		cout << e.first << " : " << e.second << endl;
	}
	cout << endl;
	cout << m.size() << endl;
}

void test5() {
	map<int, int> m;
	for (int i = 0; i < 10000; i++) {
		int r = rand() + i % 1000000;
		m[r] = r;
		if (i % 500 == 0) {
			cout << "insert size = " << m.size() << endl;
		}
	}
	for (int i = 0; i < 5000; i++) {
		int r = rand() + i % 1000000;
		m.erase(r);
		if (i % 500 == 0) {
			cout << "erase size = " << m.size() << endl;
		}
	}
}

int main() {
	//test1();
	//test2();
	//test3();
	//test4();
	test5();

	return 0;
}