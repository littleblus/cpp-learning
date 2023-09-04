#include <string>
using namespace std;

class Solution {
public:
	int minFlipsMonoIncr(string s) {
		// dp[i][0] = dp[i-1][0] + s[i] == '1' ? 1 : 0
		// dp[i][1] = min{dp[i-1][0], dp[i-1][1]} + s[i] == '1' ? 0 : 1
		int dp[2][2];
		dp[0][0] = dp[0][1] = 0;
		for (int i = 0; i < s.size(); i++) {
			dp[1][0] = dp[0][0] + (s[i] == '1' ? 1 : 0);
			dp[1][1] = min(dp[0][0], dp[0][1]) + (s[i] == '1' ? 0 : 1);
			dp[0][0] = dp[1][0];
			dp[0][1] = dp[1][1];
		}
		return min(dp[0][0], dp[0][1]);
	}
};

int main() {
	Solution s;
	s.minFlipsMonoIncr("00110");
}