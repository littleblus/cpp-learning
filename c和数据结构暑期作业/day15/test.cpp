#include <queue>
#include <map>
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

// 奇偶树
//https://leetcode.cn/problems/even-odd-tree/description/

class Solution {
	bool checkVal(int val, int mod, int prev) {
		if (val % 2 != mod)
			return true;
		if (mod == 1) {
			if (prev >= val)
				return true;
		}
		else {
			if (prev <= val)
				return true;
		}
		return false;
	}
public:
	bool isEvenOddTree(TreeNode* root) {
		queue<TreeNode*> q1, q2;
		q1.push(root);
		int mod = 1;
		int prev = INT_MIN;
		// 层序遍历
		while (!q1.empty()) {
			TreeNode* cur = q1.front();
			if (checkVal(cur->val, mod, prev))
				return false;
			else
				prev = cur->val;
			q1.pop();
			if (cur->left)
				q2.push(cur->left);
			if (cur->right)
				q2.push(cur->right);
			if (q1.empty()) {
				if (mod == 1) {
					prev = INT_MAX;
					mod = 0;
				}
				else {
					prev = INT_MIN;
					mod = 1;
				}
				swap(q1, q2);
			}
		}
		return true;
	}
};



// 数组的相对排序
//https://leetcode.cn/problems/relative-sort-array/

class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		map<int, int> elementToCount;
		unordered_set<int> numsIn2;
		vector<int> ret;
		for (auto e : arr1) {
			elementToCount[e]++;
		}
		for (auto e : arr2) {
			numsIn2.insert(e);
			for (int i = 0; i < elementToCount[e]; i++) {
				ret.push_back(e);
			}
		}
		for (auto& e : elementToCount) {
			auto it = numsIn2.find(e.first);
			if (it == numsIn2.end()) {
				for (int i = 0; i < e.second; i++) {
					ret.push_back(e.first);
				}
			}
		}
		return ret;
	}
};