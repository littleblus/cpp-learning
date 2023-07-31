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
		// ���ֵҪô�Ǿ������ڵ��ֱ�ߣ�Ҫô������
		// ��...->left->root �� ...->left->root->right->...
		// ��������˼�룬�ȼ�������Һ��ӵ�maxpath
		// �Ժ�Ϊ������ģ�������������������ֱ���Ӻ���СΪ0
		// ��󽫼�������left + right + val����resȡ��ֵ
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
		// ����һ��ֱ��������left right֮��ȡ���
		return root->val + max(leftMax, rightMax);
	}
};