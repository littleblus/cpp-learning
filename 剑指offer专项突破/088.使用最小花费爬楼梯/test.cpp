#include <vector>
using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int dp[2]{ cost[0],cost[1] };
		// f(i) = min{f(i-1), f(i-2)} + cost[i]
		for (int i = 2; i < cost.size(); i++) {
			dp[i % 2] = min(dp[0], dp[1]) + cost[i];
		}
		return min(dp[0], dp[1]);
	}
};