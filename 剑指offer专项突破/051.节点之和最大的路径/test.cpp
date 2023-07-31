#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int maxPathSum(TreeNode* root) {
		//       -------root------
		//       |               |
		//       |               |
		//      left           right
		// 最大值要么是经过根节点的直线，要么是曲线
		// 即...->left->root 或 ...->left->root->right->...
		// 后续遍历思想，先计算出左、右孩子的maxpath
		// 对和为负增益的（负数）则丢弃，即左右直径加和最小为0
		// 最后将计算结果（left + right + val）与res取大值
		res = INT_MIN;
		dfs(root);
		return res;
	}
private:
	int res;

	int dfs(TreeNode* root) {
		if (!root)
			return 0;
		int leftMax = max(0, dfs(root->left));
		int rightMax = max(0, dfs(root->right));
		res = max(res, leftMax + rightMax + root->val);
		// 返回一个直径，所以left right之间取最大
		return root->val + max(leftMax, rightMax);
	}
};