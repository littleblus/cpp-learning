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

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ret;
		if (!root)
			return ret;
		queue<TreeNode*> q1, q2;
		q1.push(root);
		int cur;
		while (!q1.empty()) {
			cur = q1.front()->val;
			if (q1.front()->left)
				q2.push(q1.front()->left);
			if (q1.front()->right)
				q2.push(q1.front()->right);
			q1.pop();
			if (q1.empty()) {
				swap(q1, q2);
				ret.push_back(cur);
			}
		}
		return ret;
	}
};