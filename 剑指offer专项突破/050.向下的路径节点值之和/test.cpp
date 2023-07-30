#include <unordered_map>
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
	int pathSum(TreeNode* root, int targetSum) {
		_target = targetSum;
		_map[0] = 1;
		return dfs(root, 0);
	}
private:
	int _target;
	unordered_map<long long, int> _map; // keyÓÃlonglong·ÀÖ¹Òç³ö

	int dfs(TreeNode* root, long long path) {
		if (!root)
			return 0;
		path += root->val;
		int count = _map[path - _target];
		_map[path]++;
		count += dfs(root->left, path);
		count += dfs(root->right, path);
		_map[path]--;
		return count;
	}
};

int main() {
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->left->right = new TreeNode(2);
	root->left->right->right = new TreeNode(1);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(-2);

	root->right = new TreeNode(-3);
	root->right->right = new TreeNode(11);

	Solution s;
	s.pathSum(root, 8);
	return 0;
}