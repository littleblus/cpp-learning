#include <vector>
using namespace std;

class Solution {
	void dfs(vector<int>& candidates, int pos, int target) {
		if (pos == candidates.size()) return;
		if (target == 0) {
			ret.push_back(cur);
			return;
		}
		// ฒปัก
		dfs(candidates, pos + 1, target);

		// ัก
		if (target - candidates[pos] >= 0) {
			cur.push_back(candidates[pos]);
			dfs(candidates, pos, target - candidates[pos]);
			cur.pop_back();
		}
	}

	vector<vector<int>> ret;
	vector<int> cur;
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		dfs(candidates, 0, target);
		return ret;
	}
};