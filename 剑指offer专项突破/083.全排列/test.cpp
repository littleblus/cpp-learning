#include <vector>
using namespace std;

class Solution {
	void dfs(vector<int>& nums, size_t i) {
		if (i == nums.size())
			ret.push_back(nums);
		else {
			for (int j = i; j < nums.size(); j++) {
				swap(nums[i], nums[j]);
				dfs(nums, i + 1);
				swap(nums[i], nums[j]);
			}
		}
	}

	vector<vector<int>> ret;
public:
	vector<vector<int>> permute(vector<int>& nums) {
		dfs(nums, 0);
		return ret;
	}
};