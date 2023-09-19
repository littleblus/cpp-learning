#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		// s�������� == t
		// f(i, j) = f(i-1, j-1) + f(i-1, j) s[i] == t[j]
		//           f(i-1, j) s[i] != t[j]
		vector<unsigned long long> dp(t.size() + 1);
		dp[0] = 1;
		for (int i = 0; i < s.size(); i++) {
			for (int j = min(i, (int)t.size() - 1); j >= 0; j--) {
				// ���ҵ������
				dp[j + 1] = dp[j + 1] + (s[i] == t[j] ? dp[j] : 0);
			}
		}
		return dp[t.size()];
	}
};