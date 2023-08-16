#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	class less {
	public:
		bool operator()(const vector<int>& v1, const vector<int>& v2) {
			if (v1[0] < v2[0])
				return true;
			else if (v1[0] == v2[0] && v1[1] < v2[1]) // v1[0] >= v2[0]
				return true;
			else
				return false;
		}
	};
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> ret;
		// 排序
		sort(intervals.begin(), intervals.end(), less());
		// 检查是否重合
		ret.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i][0] <= ret.back()[1]) {
				// 重合
				if(intervals[i][1] > ret.back()[1])
					ret.back()[1] = intervals[i][1];
			}
			else {
				// 不重合
				ret.push_back(intervals[i]);
			}
		}
		return ret;
	}
};