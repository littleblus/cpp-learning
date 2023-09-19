#include <vector>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		const int Height = triangle.size();
		vector<int> dp(Height, INT_MAX);
		dp[0] = triangle[0][0];
		for (int i = 1; i < Height; i++) {
			for (int j = i; j >= 1; j--) {
				dp[j] = triangle[i][j] + min(dp[j], dp[j - 1]);
			}
			dp[0] += triangle[i][0];
		}
		int res = dp[0];
		for (auto e : dp) {
			if (e < res) res = e;
		}
		return res;
	}
};