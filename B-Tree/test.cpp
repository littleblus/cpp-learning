#include "bTree.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

auto split(const string& str, char delim) {
	int num = 0;
	vector<int> v;
	for (auto ch : str) {
		if (ch == delim) {
			v.push_back(num);
			num = 0;
		}
		else {
			num = num * 10 + ch - '0';
		}
	}
	if (num != 0) {
		v.push_back(num);
	}
	return v;
}

int main() {
	string s = "89 93 8 37 36 87 14 59 71 65 54 57 56 2 52 46 68 80 15 12";
	vector<int> v = split(s, ' ');
	
	bTree<int, 5> tree;
	for (auto& e : v) {
		tree.insert(e);
	}
	tree.inorder();
	return 0;
}