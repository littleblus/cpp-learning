#include <vector>
#include <queue>
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

// �������Ĳ������ II
//https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
		reverse(ret.begin(), ret.end());
		return ret;
	}
};



// ������������˫������
//https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking

class Solution {
	TreeNode* _prev;
	TreeNode* _head;

	void dfs(TreeNode* root) {
		if (!root)
			return;
		dfs(root->left);
		root->left = _prev;
		if (_prev)
			_prev->right = root;
		else // ��¼ͷ�ڵ�
			_head = root;
		_prev = root;
		dfs(root->right);
	}
public:
	TreeNode* Convert(TreeNode* pRootOfTree) {
		_prev = nullptr;
		// �������
		dfs(pRootOfTree);
		return _head;
	}
};



// ��ǰ��������������й��������
//https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

private:
	TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
		// �ݹ���ֹ����
		if (preStart > preEnd || inStart > inEnd) {
			return nullptr;
		}

		// ������ڵ�
		int rootVal = preorder[preStart];
		TreeNode* root = new TreeNode(rootVal);

		// ����������������ҵ����ڵ��λ��
		int rootIndex;
		for (int i = inStart; i <= inEnd; i++) {
			if (inorder[i] == rootVal) {
				rootIndex = i;
				break;
			}
		}

		// ����������
		int leftSize = rootIndex - inStart;
		root->left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, rootIndex - 1);

		// ����������
		root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, rootIndex + 1, inEnd);

		return root;
	}
};



// ������ͺ���������й��������
//https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class Solution {
	TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
		if (inStart > inEnd || postStart > postEnd)
			return nullptr;
		// ����root
		int rootVal = postorder[postEnd];
		TreeNode* root = new TreeNode(rootVal);

		int i;
		for (i = inStart; i <= inEnd; i++) {
			if (inorder[i] == rootVal)
				break;
		}
		int leftSize = i - inStart;

		root->left = build(inorder, inStart, i - 1, postorder, postStart, postStart + leftSize - 1);
		root->right = build(inorder, i + 1, inEnd, postorder, postStart + leftSize, postEnd - 1);

		return root;
	}
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		// ����[left tree] root [right tree]
		// ����[left tree] [right tree] root
		return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
};



// ������ǰ������ǵݹ�
//https://leetcode.cn/problems/binary-tree-preorder-traversal/

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur || !st.empty()) {
			// ������ڵ� ��� ��ջ
			// ������ �ڵ��Ϊ��һ���ڵ���ҽڵ� ��ջ��
			while (cur) {
				ret.push_back(cur->val);
				st.push(cur);
				cur = cur->left;
			}
			cur = st.top()->right;
			st.pop();
		}
		return ret;
	}
};



// ��������������ǵݹ�
//https://leetcode.cn/problems/binary-tree-inorder-traversal/

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur || !st.empty()) {
			// ������ڵ� ��ջ
			// ������ ��� �ڵ��Ϊ��һ���ڵ���ҽڵ� ��ջ��
			while (cur) {
				st.push(cur);
				cur = cur->left;
			}
			ret.push_back(st.top()->val);
			cur = st.top()->right;
			st.pop();
		}
		return ret;
	}
};



// ��������������ǵݹ�
//https://leetcode.cn/problems/binary-tree-postorder-traversal/

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> st;
		TreeNode* cur(root), * prev(nullptr);
		while (cur || !st.empty()) {
			// ������ڵ� ��ջ
			while (cur) {
				st.push(cur);
				cur = cur->left;
			}
			// ��ʱcurΪ�գ����ջ���ڵ���������ǿջ�����prev����������ʹ��ˣ����
			if (st.top()->right == nullptr || st.top()->right == prev) {
				ret.push_back(st.top()->val);
				prev = st.top();
				st.pop();
			}
			else {
				cur = st.top()->right;
			}
		}
		return ret;
	}
};