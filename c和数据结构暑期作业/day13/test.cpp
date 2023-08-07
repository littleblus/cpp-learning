#include <string>
#include <unordered_set>
using namespace std;

// 整理字符串
//https://leetcode.cn/problems/make-the-string-great/description/

class Solution {
public:
	string makeGood(string s) {
		string ret;
		for (auto e : s) {
			if (!ret.empty() && abs(e - ret.back()) == 32)
				ret.pop_back();
			else
				ret += e;
		}
		return ret;
	}
};



// 开幕式焰火
//https://leetcode.cn/problems/sZ59z6/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	unordered_set<int> _s;
public:
	int numColor(TreeNode* root) {
		if (!root)
			return 0;
		_s.insert(root->val);
		numColor(root->left);
		numColor(root->right);

		return _s.size();
	}
};