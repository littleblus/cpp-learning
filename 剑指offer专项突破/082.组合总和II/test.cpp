#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
	size_t getNext(vector<int>& arr, size_t pos) {
		int num = arr[pos];
		size_t i = pos;
		while (i < arr.size() && arr[i] == num)
			i++;
		return i;
	}

	void dfs(vector<int>& arr, size_t pos, int target) {
		if (target == 0) {
			ret.push_back(cur);
			return;
		}
		else if (target < 0 || pos >= arr.size())
			return;

		// ัก
		cur.push_back(arr[pos]);
		if(target - arr[pos] >= 0)
			dfs(arr, pos + 1, target - arr[pos]);
		cur.pop_back();

		// ฒปัก
		size_t next = getNext(arr, pos);
		dfs(arr, next, target);
	}

	vector<vector<int>> ret;
	vector<int> cur;
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		dfs(candidates, 0, target);
		return ret;
	}
};