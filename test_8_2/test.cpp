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

// 二叉树的层序遍历 II
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



// 二叉搜索树与双向链表
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
		else // 记录头节点
			_head = root;
		_prev = root;
		dfs(root->right);
	}
public:
	TreeNode* Convert(TreeNode* pRootOfTree) {
		_prev = nullptr;
		// 中序遍历
		dfs(pRootOfTree);
		return _head;
	}
};



// 从前序与中序遍历序列构造二叉树
//https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

private:
	TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
		// 递归终止条件
		if (preStart > preEnd || inStart > inEnd) {
			return nullptr;
		}

		// 构造根节点
		int rootVal = preorder[preStart];
		TreeNode* root = new TreeNode(rootVal);

		// 在中序遍历序列中找到根节点的位置
		int rootIndex;
		for (int i = inStart; i <= inEnd; i++) {
			if (inorder[i] == rootVal) {
				rootIndex = i;
				break;
			}
		}

		// 构造左子树
		int leftSize = rootIndex - inStart;
		root->left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, rootIndex - 1);

		// 构造右子树
		root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, rootIndex + 1, inEnd);

		return root;
	}
};



// 从中序和后序遍历序列构造二叉树
//https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class Solution {
	TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
		if (inStart > inEnd || postStart > postEnd)
			return nullptr;
		// 构建root
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
		// 中序：[left tree] root [right tree]
		// 后序：[left tree] [right tree] root
		return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
};



// 二叉树前序遍历非递归
//https://leetcode.cn/problems/binary-tree-preorder-traversal/

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur || !st.empty()) {
			// 遇到左节点 输出 入栈
			// 遇到空 节点改为上一个节点的右节点 出栈顶
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



// 二叉树中序遍历非递归
//https://leetcode.cn/problems/binary-tree-inorder-traversal/

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur || !st.empty()) {
			// 遇到左节点 入栈
			// 遇到空 输出 节点改为上一个节点的右节点 出栈顶
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



// 二叉树后序遍历非递归
//https://leetcode.cn/problems/binary-tree-postorder-traversal/

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> st;
		TreeNode* cur(root), * prev(nullptr);
		while (cur || !st.empty()) {
			// 遇到左节点 入栈
			while (cur) {
				st.push(cur);
				cur = cur->left;
			}
			// 此时cur为空，如果栈顶节点的右子树是空或者是prev，都代表访问过了，输出
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