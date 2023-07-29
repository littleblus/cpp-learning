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
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> q1, q2;
		int left = 0;
		q1.push(root);
		while (1) {
			left = (!q1.empty() && q1.front()) ? q1.front()->val : left;
			while (!q1.empty()) {
				if (q1.front()->left)
					q2.push(q1.front()->left);
				if (q1.front()->right)
					q2.push(q1.front()->right);
				q1.pop();
			}
			left = (!q2.empty() && q2.front()) ? q2.front()->val : left;
			while (!q2.empty()) {
				if (q2.front()->left)
					q1.push(q2.front()->left);
				if (q2.front()->right)
					q1.push(q2.front()->right);
				q2.pop();
			}
			if (q1.empty() && q2.empty())
				break;
		}
		return left;
	}
};