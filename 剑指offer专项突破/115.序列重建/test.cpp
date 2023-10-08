#include <vector>

#include <queue>

using namespace std;

class Solution {
public:
	bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
		vector<vector<int>> graph(nums.size() + 1);
		vector<int> inDegrees(nums.size() + 1);
		for (auto& v : sequences) {
			for (int i = 1; i < v.size(); i++) {
				graph[v[i - 1]].emplace_back(v[i]);
				++inDegrees[v[i]];
			}
		}
		queue<int> que;
		for (int i = 1; i < inDegrees.size(); i++) {
			if (inDegrees[i] == 0)
				que.emplace(i);
		}
		while (!que.empty()) {
			if (que.size() > 1)
				return false;
			for (int e : graph[que.front()]) {
				if (--inDegrees[e] == 0) {
					que.emplace(e);
				}
			}
			que.pop();
		}
		return true;
	}
};

int main() {
	vector<int> nums{ 4,1,5,2,6,3 };
	vector<vector<int>> vv{ {5,2,6,3},{4,1,5,2} };
	Solution sol;
	sol.sequenceReconstruction(nums, vv);
}