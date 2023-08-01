
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
	TreeNode* increasingBST(TreeNode* root) {
		// ��������Ҷ�ӽڵ�
		TreeNode* cur = root;
		while (cur->left) {
			cur = cur->left;
		}
		_root = new TreeNode(-1, nullptr, nullptr);
		TreeNode* del = _root;
		dfs(root);
		TreeNode* ret = del->right;
		delete del;
		return ret;
	}
private:
	TreeNode* _root;

	TreeNode* dfs(TreeNode* root) {
		// �������
		if (!root) {
			return nullptr;
		}
		TreeNode* leftchild = dfs(root->left);
		_root->right = new TreeNode(root->val);
		_root = _root->right;
		TreeNode* rightchild = dfs(root->right);

		return root;
	}
};