#include <vector>
using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		// f(i) = sum{f(i-nums[j]) + 1}
		vector<size_t> dp(target + 1);
		dp[0] = 1;
		for (int i = 1; i <= target; i++) {
			size_t sum = 0;
			for (int e : nums) {
				if (i >= e) {
					sum += dp[i - e];
				}
			}
			dp[i] = sum;
		}
		return dp[target];
	}
};