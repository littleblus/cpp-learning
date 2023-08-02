#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		TreeNode* cur(root), * ret(nullptr);
		while (cur) {
			if (p->val < cur->val) {
				ret = cur;
				cur = cur->left;
			}
			else {
				cur = cur->right;
			}
		}
		return ret;
	}
};