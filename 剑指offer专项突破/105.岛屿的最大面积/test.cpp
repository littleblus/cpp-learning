#include <vector>
#include <queue>
using namespace std;

class Solution {
	int getArea(vector<vector<int>>& grid, 
		vector<vector<char>>& visited, 
		int i, int j, int ROW, int COL) {
		queue<pair<int, int>> que;
		que.push({ i,j });
		visited[i][j] = true;
		pair<int, int> move[]{ {0,1},{0,-1},{-1,0},{1,0} };
		int ret = 0;
		while (!que.empty()) {
			int row = que.front().first;
			int col = que.front().second;
			que.pop();
			ret++;
			for (auto& mv : move) {
				int r = row + mv.first;
				int c = col + mv.second;
				if (r >= 0 && r < ROW && c >= 0 && c < COL &&
					grid[r][c] && !visited[r][c]) {
					que.push({ r,c });
					visited[r][c] = true;
				}
			}
		}
		return ret;
	}
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		const int ROW(grid.size()), COL(grid[0].size());
		// 用char存放bool，提高效率
		vector<vector<char>> visited(ROW, vector<char>(COL, false));
		int res = 0;
		for (size_t i = 0; i < ROW; i++) {
			for (size_t j = 0; j < COL; j++) {
				if (grid[i][j] && !visited[i][j]) {
					int area = getArea(grid, visited, i, j, ROW, COL);
					res = max(res, area);
				}
			}
		}
		return res;
	}
};