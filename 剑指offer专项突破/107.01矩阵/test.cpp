#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		const int ROW(mat.size()), COL(mat[0].size());
		vector<vector<int>> ret(ROW, vector<int>(COL));
		queue<pair<int, int>> que; // ´æ·Å0µÄ×ø±ê
		for (size_t i = 0; i < ROW; i++) {
			for (size_t j = 0; j < COL; j++) {
				if (mat[i][j] == 0) {
					que.push({ i,j });
					ret[i][j] = 0;
				}
				else {
					ret[i][j] = INT_MAX;
				}
			}
		}
		pair<int, int> move[4] = { {-1,0},{1,0},{0,-1},{0,1} };
		while (!que.empty()) {
			int posr = que.front().first;
			int posc = que.front().second;
		}
	}
};

int main() {
	vector<vector<int>> v{ {0,0,0},{0,1,0},{1,1,1} };
	Solution sol;
	sol.updateMatrix(v);
	return 0;
}