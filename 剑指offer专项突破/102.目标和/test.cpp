#include <vector>
using namespace std;

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		// + <=> p  - <=> q    p - q = target
		//                     p + q = sum
		//                     2p = target + sum
		//                     p = (target + sum) / 2;
		int sum(0);
		for (auto e : nums) {
			sum += e;
		}
		if ((target + sum) % 2 != 0 || sum < target)
			return 0;
		int p = target + sum >> 1;
		vector<int> dp(p + 1, 0);
		// 初始化第一行，f(0, 0) = 1 , f(0, j) = 0
		dp[0] = 1;
		for (int i = 0; i < nums.size(); i++) {
			int num = nums[i];
			for (int j = dp.size() - 1; j >= num; j--) {
				dp[j] = dp[j] + (j - num >= 0 ? dp[j - num] : 0);
			}
		}
		return dp.back();
	}
};

int main() {
	vector<int> test{ 1,1,1,1,1 };
	Solution sol;
	sol.findTargetSumWays(test, 3);
	return 0;
}