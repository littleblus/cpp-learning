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
	int sumNumbers(TreeNode* root) {	
		return dfs(root, 0);
	}
private:
	int dfs(TreeNode* root, int path) {
		if (!root)
			return 0;
		path = path * 10 + root->val;
		if (!root->left && !root->right)
			return path;
		int left = dfs(root->left, path);
		int right = dfs(root->right, path);
		return left + right;
	}
};