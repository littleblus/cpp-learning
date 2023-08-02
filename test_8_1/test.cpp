#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 根据二叉树创建字符串
//https://leetcode.cn/problems/construct-string-from-binary-tree/

class Solution {
	string _core(TreeNode* root) {
		if (!root)
			return "()";
		string left, right;
		if (root->left || root->right)
			left = _core(root->left);
		if (root->right)
			right = _core(root->right);
		return "(" + to_string(root->val) + left + right + ")";
	}
public:
	string tree2str(TreeNode* root) {
		string ret = _core(root);
		ret.erase(ret.begin());
		ret.pop_back();
		return ret;
	}
};



// 二叉树的层序遍历
//https://leetcode.cn/problems/binary-tree-level-order-traversal/

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if (!root)
			return ret;
		ret.push_back(vector<int>());
		queue<TreeNode*> up, down;
		up.push(root);
		while (!up.empty()) {
			if (up.front()->left)
				down.push(up.front()->left);
			if (up.front()->right)
				down.push(up.front()->right);
			ret.back().push_back(up.front()->val);
			up.pop();
			if (up.empty()) {
				swap(up, down);
				if (!up.empty())
					ret.push_back(vector<int>());
			}
		}
		return ret;
	}
};



// 二叉树的最近公共祖先
//https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/

// O(N^2)
class Solution {
	TreeNode* _ret = nullptr;

	void dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root)
			return;
		bool pLeft, pRight, qLeft, qRight;
		pLeft = find(root->left, p);
		pRight = !pLeft;
		qLeft = find(root->left, q);
		qRight = !qLeft;
		if ((pLeft && qRight) || (pRight && qLeft) || root == p || root == q) {
			_ret = root;
			return;
		}
		if (pLeft)
			dfs(root->left, p, q);
		else
			dfs(root->right, p, q);
	}

	bool find(TreeNode* root, TreeNode* node) {
		if (!root)
			return false;
		bool left = find(root->left, node);
		bool right = find(root->right, node);
		return left || right || root == node;
	}
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if(root)
			dfs(root, p, q);
		return _ret;
	}
};

// O(N)
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q)
			return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left && right)
			return root;
		if (left)
			return left;
		if (right)
			return right;
		return nullptr;
	}
};