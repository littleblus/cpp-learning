#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};

class Solution {
	int _sum;

	void dfs(TreeNode* root) {
		if (!root)
			return;
		dfs(root->right);
		_sum += root->val;
		root->val = _sum;
		dfs(root->left);
	}
public:
	TreeNode* convertBST(TreeNode* root) {
		// µ¹×ÅÖÐÐò±éÀú
		_sum = 0;
		dfs(root);
		return root;
	}
};