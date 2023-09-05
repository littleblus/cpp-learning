#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int lenLongestFibSubseq(vector<int>& arr) {
		unordered_map<int, int> hashmap;
		for (int i = 0; i < arr.size(); i++) {
			hashmap[arr[i]] = i;
		}
		vector<vector<int>> dp(arr.size(), vector<int>(arr.size()));
		int ret = 2;
		for (int i = 1; i < arr.size(); i++) {
			for (int j = 0; j < i; j++) {
				auto it = hashmap.find(arr[i] - arr[j]);
				if (it != hashmap.end() && it->second < j) {
					dp[i][j] = dp[j][it->second] + 1;
				}
				else {
					dp[i][j] = 2;
				}
				ret = max(ret, dp[i][j]);
			}
		}
		return ret == 2 ? 0 : ret;
	}
};