#include <vector>
using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int target(0), maxVal(0);
		for (auto e : nums) {
			target += e;
			maxVal = max(maxVal, e);
		}
		if (target % 2 != 0)
			return false;
		target >>= 1;
		if (maxVal > target)
			return false;
		vector<int> dp(target + 1, false); // vector bool效率太低
		// 初始化第一行，f(0, 0) = T , f(0, j) = F
		dp[0] = true;
		for (int i = 1; i < nums.size(); i++) {
			int num = nums[i];
			for (int j = dp.size() - 1; j >= num; j--) {
				if (!dp[j])
					dp[j] = j - num >= 0 ? dp[j - num] : false;
			}
		}
		return dp.back();
	}
};

int main() {
	vector<int> test{ 3,3,3,4,5 };
	Solution sol;
	sol.canPartition(test);
	return 0;
}