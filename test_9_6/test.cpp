#include "AVLtree.h"
#include <vector>
using namespace std;

int main() {
	AVLtree<int> tree;
	vector<int> v{ 5,8,3,4,0,36,2,14 };
	for (auto e : v) {
		tree.insert(e);
		tree.isAVL();
	}
	tree.printInorder();
	return 0;
}