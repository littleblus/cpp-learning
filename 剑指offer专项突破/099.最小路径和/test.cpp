#include <vector>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		const int M(grid.size()), N(grid[0].size());
		vector<int> dp(N);
		dp[0] = grid[0][0];
		for (int i = 1; i < N; i++) {
			dp[i] = dp[i - 1] + grid[0][i];
		}
		for (int i = 1; i < M; i++) {
			dp[0] += grid[i][0];
			for (int j = 1; j < N; j++) {
				dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
			}
		}
		return dp[N - 1];
	}
};