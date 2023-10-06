#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
	enum STATE {
		NotVisited,
		Searching,
		Completed
	};

	void dfs(stack<int>& st, int pos) {
		if (status[pos] == Completed)
			return;
		else if (status[pos] == Searching)
			throw "loop";
		status[pos] = Searching;
		for (size_t i = 0; i < map.size(); i++) {
			if (map[pos][i] == 1 && status[i] != Completed) {
				try {
					dfs(st, i);
				}
				catch (const char* e) {
					throw e;
				}
			}
		}
		status[pos] = Completed;
		st.push(pos);
	}

	vector<vector<char>> map;
	vector<STATE> status;
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		if (numCourses == 1) {
			return { 0 };
		}
		// 建立图
		map = vector<vector<char>>(numCourses, vector<char>(numCourses, 0));
		status = vector<STATE>(numCourses, NotVisited);
		for (size_t i = 0; i < prerequisites.size(); i++) {
			int after(prerequisites[i][0]), cur(prerequisites[i][1]);
			map[cur][after] = 1;
		}
		// 搜索
		stack<int> st;
		for (size_t i = 0; i < map.size(); i++) {
			if (status[i] == NotVisited) {
				try {
					dfs(st, i);
				}
				catch (const char* e) {
					return {};
				}
			}
		}
		// 展开栈
		vector<int> ret;
		while (!st.empty()) {
			ret.emplace_back(st.top());
			st.pop();
		}
		return ret;
	}
};

int main() {
	vector<vector<int>> vv{ {1,0}, {0,1} };
	Solution sol;
	sol.findOrder(2, vv);
}