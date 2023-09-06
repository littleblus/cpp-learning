#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		const int N = s.size();
		vector<vector<bool>> isPal(N, vector<bool>(N));
		for (size_t i = 0; i < N; i++) {
			for (size_t j = 0; j <= i; j++) {
				if (s[i] == s[j] && (i <= j + 1 || isPal[j + 1][i - 1]))
					isPal[j][i] = true;
			}
		}

		vector<int> dp(N, 0);
		for (size_t i = 1; i < N; i++) {
			if (isPal[0][i])
				dp[i] = 0;
			else {
				dp[i] = i;
				for (size_t j = 1; j <= i; j++) {
					if (isPal[j][i])
						dp[i] = min(dp[i], dp[j - 1] + 1);
				}
			}
		}
		return dp[N - 1];
	}
};

int main() {
	Solution s;
	s.minCut("aab");
}