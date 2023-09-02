#include <vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		// f(i) = max{f(i-1), f(i-2) + nums[i]}
		int dp[2]{ nums[0], max(nums[0],nums[1]) };
		for (int i = 2; i < nums.size(); i++) {
			// left right cur
			int cur = i % 2;
			int left(0), right(1);
			if (cur == 1) {
				left = 1;
				right = 0;
			}
			dp[cur] = max(dp[left] + nums[i], dp[right]);
		}
		return max(dp[0], dp[1]);
	}
};