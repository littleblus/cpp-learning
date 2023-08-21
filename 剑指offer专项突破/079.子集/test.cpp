#include <vector>
using namespace std;

class Solution {
	void dfs(vector<int>& nums, size_t pos) {
		if (pos == nums.size()) {
			ret.push_back(cur);
			return;
		}
		cur.push_back(nums[pos]);
		dfs(nums, pos + 1);
		cur.pop_back();

		dfs(nums, pos + 1);
	}

	vector<vector<int>> ret;
	vector<int> cur;
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		dfs(nums, 0);
		return ret;
	}
};