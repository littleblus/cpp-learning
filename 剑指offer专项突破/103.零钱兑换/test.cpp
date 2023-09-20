#include <vector>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		// f(i) = f(i-coins[i]) + 1
		vector<int> dp(amount + 1);
		for (int i = 1; i <= amount; i++) {
			dp[i] = amount + 1;
			for (auto e : coins) {
				if (i >= e) {
					dp[i] = min(dp[i], dp[i - e] + 1);
				}
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}
};