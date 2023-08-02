#include <iostream>
#include "BSTree.h"
using namespace std;

void test1() {
	int arr[10]{ 8,12,3,79,34,67,88,25,9,30 };
	BSTree<int> tree;
	for (auto e : arr) {
		tree.insert(e);
	}
	tree.printInOrder();

	tree.erase(79);
	tree.printInOrder();

	tree.erase(34);
	tree.printInOrder();

	tree.erase(12);
	tree.printInOrder();

	tree.erase(30);
	tree.printInOrder();

	tree.erase(8);
	tree.printInOrder();

	for (auto e : arr) {
		tree.erase(e);
	}
	tree.printInOrder();
}

void test2() {
	int arr[10]{ 8,12,3,79,34,67,88,25,9,30 };
	BSTree<int> tree;
	for (auto e : arr) {
		tree.insert(e);
	}
	tree.printInOrder();
}

void test3() {
	int arr[10]{ 8,12,3,79,34,67,88,25,9,30 };
	BSTree<int> tree;
	for (auto e : arr) {
		tree.insert(e);
	}
	tree.printInOrder();

	BSTree<int> treeCopy(tree);
	treeCopy.printInOrder();
}

int main() {
	//test1();
	//test2();
	test3();

	return 0;
}