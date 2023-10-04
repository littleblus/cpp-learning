#include <vector>
using namespace std;

class Solution {
	struct trieNode {
		trieNode* child[2]{ nullptr,nullptr };
	};
public:
	int findMaximumXOR(vector<int>& nums) {
		trieNode* root = new trieNode;
		for (int e : nums) {
			trieNode* cur = root;
			for (int i = 31; i >= 0; i--) {
				int bit = (e >> i) & 1;
				if (cur->child[bit] == nullptr)
					cur->child[bit] = new trieNode;
				cur = cur->child[bit];
			}
		}
		int res = 0;
		for (int e : nums) {
			trieNode* cur = root;
			int tmp = 0;
			for (int i = 31; i >= 0; i--) {
				int bit = (e >> i) & 1;
				if (cur->child[1 - bit]) {
					tmp = (tmp << 1) + 1;
					cur = cur->child[1 - bit];
				}
				else {
					tmp <<= 1;
					cur = cur->child[bit];
				}
			}
			if (tmp > res)
				res = tmp;
		}
		return res;
	}
};