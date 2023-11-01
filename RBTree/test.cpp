#include <iostream>
#include <map>
#include "RBTree.h"

using namespace std;
using blus::RBTree;

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

int main() {
	test1();
	
	return 0;
}