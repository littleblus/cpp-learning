#include <unordered_set>
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
	unordered_set<int> _set;
public:
	bool findTarget(TreeNode* root, int k) {
		// ¹þÏ£±í
		if (!root)
			return false;
		bool left = findTarget(root->left, k);
		if (_set.find(k - root->val) != _set.end())
			return true;
		_set.insert(root->val);
		bool right = findTarget(root->right, k);
		
		return left || right;
	}
};