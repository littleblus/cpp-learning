#define NULL (0)

// 二叉搜索树与双向链表
// https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
	void _core(TreeNode* root) {
		if (!root) return;
		if (root->left) _core(root->left);
		if (prev) {
			root->left = prev;
			prev->right = root;
			if (!head) head = prev;
		}
		prev = root;
		if (root->right) _core(root->right);
	}
public:
	TreeNode* Convert(TreeNode* pRootOfTree) {
		if (!pRootOfTree) return nullptr;
		if (!pRootOfTree->left && !pRootOfTree->right) return pRootOfTree;
		_core(pRootOfTree);
		return head;
	}
private:
	TreeNode* prev = nullptr;
	TreeNode* head = nullptr;
};



// 二叉树的最近公共祖先
// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/
class Solution {
	TreeNode* _core(TreeNode* root) {
		if (!root) return nullptr;
		if (root == _p || root == _q) return root;
		TreeNode* lret = _core(root->left);
		TreeNode* rret = _core(root->right);
		if (lret && rret) return root;
		if (lret) return lret;
		if (rret) return rret;
		return nullptr;
	}
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		_p = p, _q = q;
		return _core(root);
	}
private:
	TreeNode* _p;
	TreeNode* _q;
};