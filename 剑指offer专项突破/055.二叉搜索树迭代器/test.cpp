#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
	TreeNode* _cur;
	stack<TreeNode*> _st;
public:
	BSTIterator(TreeNode* root) 
		: _cur(root)
	{}

	int next() {
		// 保证next()调用是有效的
		while (_cur) {
			_st.push(_cur);
			_cur = _cur->left;
		}
		int val = _st.top()->val;
		_cur = _st.top()->right;
		_st.pop();
		return val;
	}

	bool hasNext() {
		return _cur || !_st.empty();
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */