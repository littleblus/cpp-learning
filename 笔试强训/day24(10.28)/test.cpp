#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 年终奖
class Bonus {
public:
	int getMost(vector<vector<int>> board) {
		vector<vector<int>> dp(2, vector<int>(6));
		dp[0][0] = board[0][0];
		for (int i = 1; i < 6; i++)
			dp[0][i] = dp[0][i - 1] + board[0][i];
		for (int i = 1; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				dp[1][j] = max(dp[0][j], j > 0 ? dp[1][j - 1] : 0) + board[i][j];
			}
			swap(dp[0], dp[1]);
		}
		return dp[0][5];
	}
};



// 迷宫问题
vector<pair<int, int>> path;
pair<int, int> mv[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
vector<vector<char>> visited;

void dfs(const vector<vector<int>>& board, int i, int j) {
	// 深搜
	if (i == board.size() - 1 && j == board[0].size() - 1) {
		for (auto& p : path) {
			cout << "(" << p.first << "," << p.second << ")" << endl;
		}
		cout << "(" << i << "," << j << ")" << endl;
		return;
	}
	for (int k = 0; k < 4; k++) {
		int x = i + mv[k].first;
		int y = j + mv[k].second;
		if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && visited[x][y] == false && board[x][y] == 0) {
			path.push_back({ i, j });
			visited[i][j] = true;
			dfs(board, x, y);
			visited[i][j] = false;
			path.pop_back();
		}
	}
}

int main() {
	int row, col;
	cin >> row >> col;
	vector<vector<int>> board(row, vector<int>(col));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> board[i][j];
		}
	}
	visited = vector<vector<char>>(row, vector<char>(col, false));
	visited[0][0] = true;
	dfs(board, 0, 0);
	return 0;
}