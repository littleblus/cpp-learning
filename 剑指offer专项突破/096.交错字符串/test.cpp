#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size())
			return false;
		// 降低空间复杂度到min(s1.size, s2.size)
		if (s1.size() < s2.size())
			return isInterleave(s2, s1, s3);
		vector<bool> dp(s2.size() + 1);
		// dp(i, j) = (s3[i+j+1] == s1[i] && dp(i-1, j)) || (s3[i+j+1] == s2[j] && dp(i, j-1))
		// 初始化第1行(i == -1)
		dp[0] = true;
		for (int j = 0; j < s2.size() && s2[j] == s3[j]; j++) {
			dp[j + 1] = true;
		}
		// dp
		for (int i = 0; i < s1.size(); i++) {
			dp[0] = dp[0] && (s1[i] == s3[i]);
			for (int j = 0; j < s2.size(); j++) {
				dp[j + 1] = (s3[i + j + 1] == s1[i] && dp[j + 1]) || (s3[i + j + 1] == s2[j] && dp[j]);
			}
		}
		return dp[s2.size()];
	}
};