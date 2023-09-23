#define _CRT_SECURE_NO_WARNINGS
#include "AVLtree.h"
#include <vector>
using namespace std;

void test0() {
	freopen("output.txt", "w", stdout);
	const int N = 100;
	srand(time(0));
	for (int i = 0; i < N; i++) {
		printf("%d ", rand() % 100);
	}
}

void test1() {
	freopen("output.txt", "r", stdin);
	const int N = 100;
	AVLtree<int> tree;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	for (int i = 0; i < N; i++) {
		tree.insert(v[i]);
		tree.isAVL();
	}
	tree.printInorder();
}

void test2() {
	const int N = 1000;
	AVLtree<int> tree;
	vector<int> v(N);
	srand(time(0));
	for (int i = 0; i < N; i++) {
		v[i] = rand() % (10 * N);
	}
	for (int i = 0; i < N; i++) {
		tree.insert(v[i]);
		tree.isAVL();
	}
	tree.printInorder();
	cout << endl;
	cout << tree.isAVL() << endl;
}

int main() {
	test2();
	return 0;
}