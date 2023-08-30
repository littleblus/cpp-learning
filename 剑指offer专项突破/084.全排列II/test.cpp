#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
	void dfs(vector<int>& nums, size_t i) {
		if (i >= nums.size())
			ret.push_back(nums);
		else {
			unordered_set<int> set;
			for (int j = i; j < nums.size(); j++) {
				if (set.count(nums[j]) == 0) {
					set.insert(nums[j]);
					swap(nums[i], nums[j]);
					dfs(nums, i + 1);
					swap(nums[i], nums[j]);
				}
			}
		}
	}

	vector<vector<int>> ret;
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		dfs(nums, 0);
		return ret;
	}
};