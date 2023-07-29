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

class CBTInserter {
public:
	CBTInserter(TreeNode* root) {
		_root = root;
		_q.push(_root);
		while (!_q.empty()) {
			TreeNode* front = _q.front();
			if (front->left && front->right) {
				_q.push(front->left);
				_q.push(front->right);
			}
			else {
				break;
			}
			_q.pop();
		}
	}

	int insert(int v) {
		TreeNode* front = _q.front();
		if (front->left == nullptr) {
			front->left = new TreeNode(v);
		}
		else {
			front->right = new TreeNode(v);
			_q.push(front->left);
			_q.push(front->right);
			_q.pop();
		}
		return front->val;
	}

	TreeNode* get_root() {
		return _root;
	}
private:
	TreeNode* _root;
	queue<TreeNode*> _q;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */