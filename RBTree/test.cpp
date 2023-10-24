#include <iostream>
#include "RBTree.h"

using namespace std;
using blus::RBTree;

void test1() {
	RBTree<int> t;
	t.Insert(10);
	t.Insert(2);
	t.Insert(6);
	t.Insert(1);
	t.Insert(5);
	t.Insert(8);
	t.PrintInOrder();
}

int main() {
	test1();
	return 0;
}