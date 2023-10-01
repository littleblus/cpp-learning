#include <vector>
#include <list>

using namespace std;

class Solution {
	void dfs(vector<vector<int>>& graph, int cur) {
		path.emplace_back(cur);
		if (cur == graph.size() - 1)
			ret.emplace_back(path);
		else {
			for (int e : graph[cur]) {
				dfs(graph, e);
			}
		}
		path.pop_back();
	}

	vector<int> path;
	vector<vector<int>> ret;
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		// dfs µœ÷
		dfs(graph, 0);
		return ret;
	}
};