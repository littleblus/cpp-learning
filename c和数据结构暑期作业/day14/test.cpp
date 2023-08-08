#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 从根到叶的二进制数之和
//https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/

class Solution {
	int dfs(TreeNode* root, int val) {
		if (!root)
			return 0;
		val = (val << 1) + root->val;
		if (root->left == nullptr && root->right == nullptr)
			return val;
		return dfs(root->left, val) + dfs(root->right, val);
	}
public:
	int sumRootToLeaf(TreeNode* root) {
		return dfs(root, 0);
	}
};



// 二叉树的坡度
//https://leetcode.cn/problems/binary-tree-tilt/

class Solution {
	int sum;
	int dfs(TreeNode* root) {
		if (!root)
			return 0;
		int left = dfs(root->left);
		int right = dfs(root->right);
		sum += abs(left - right);
		//cout << left << ' ' << right << ' ' << sum << endl;
		return root->val + left + right;
	}
public:
	int findTilt(TreeNode* root) {
		sum = 0;
		dfs(root);
		return sum;
	}
};