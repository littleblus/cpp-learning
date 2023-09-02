#include <vector>
using namespace std;

class Solution {
	int core(vector<int>& nums, int start, int end) {
		// f(i) = max{f(i-1), f(i-2) + nums[i]}
		int dp[2]{ nums[start], max(nums[start], nums[start + 1]) };
		for (int i = start + 2; i < end; i++) {
			// left right cur
			int cur = (i - start) % 2;
			int left(0), right(1);
			if (cur == 1) {
				left = 1;
				right = 0;
			}
			dp[cur] = max(dp[left] + nums[i], dp[right]);
		}
		return max(dp[0], dp[1]);
	}
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		else if (nums.size() == 2)
			return max(nums[0], nums[1]);
		else
			return max(core(nums, 0, nums.size() - 1), core(nums, 1, nums.size()));
	}
};