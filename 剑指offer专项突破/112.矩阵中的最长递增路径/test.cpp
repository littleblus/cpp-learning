#include <vector>

using namespace std;

class Solution {
	int dfs(vector<vector<int>>& matrix, int i, int j) {
		if (length[i][j]) {
			return length[i][j];
		}
		else {
			pair<int, int> move[]{ {-1,0},{1,0},{0,-1},{0,1} };
			int maxlen = 1;
			for (auto [x, y] : move) {
				int r(i + x), c(j + y);
				if (r >= 0 && r < row && c >= 0 && c < col && matrix[r][c] > matrix[i][j])
					maxlen = max(maxlen, dfs(matrix, r, c) + 1);
			}
			length[i][j] = maxlen;
			return maxlen;
		}
	}

	vector<vector<int>> length;
	int row;
	int col;
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		row = matrix.size();
		col = matrix[0].size();
		if (row == 0 || col == 0)
			return 0;
		length = vector<vector<int>>(row, vector<int>(col, 0));
		int res = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int len = dfs(matrix, i, j);
				res = len > res ? len : res;
			}
		}
		return res;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> vv{ {9,9,4} ,{6,6,8},{2,1,1} };
	sol.longestIncreasingPath(vv);

	return 0;
}