#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 红包
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		int king = gifts[0];
		int count = 0;
		for (size_t i = 0; i < n; i++) {
			if (gifts[i] == king) count++;
			else count--;
			if (count == 0) king = gifts[i];
		}
		count = 0;
		for (auto e : gifts) {
			if (e == king) count++;
		}
		if (count > n / 2) return king;
		else return 0;
	}
};



// 字符串的最短编辑距离
int EditDistance(string& start, string& target) {
	int m = start.size();
	int n = target.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	// 初始化，第一行和第一列分别为0~m和0~n
	// 其中dp[i][j]表示start的前i个字符转换为target的前j个字符所需要的最少操作数
	for (int i = 0; i <= m; i++) {
		dp[i][0] = i;
	}
	for (int j = 0; j <= n; j++) {
		dp[0][j] = j;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			// 如果当前字符相等，则不需要操作，直接取左上角的值
			// 如果当前字符不相等，则需要操作，取左上角的值+1
			int left = dp[i][j - 1] + 1;
			int down = dp[i - 1][j] + 1;
			int left_down = dp[i - 1][j - 1] + (start[i - 1] != target[j - 1] ? 1 : 0);
			// 三种情况取最小值
			dp[i][j] = min(left, min(down, left_down));
		}
	}
	return dp[m][n];
}

int main() {
	string start, target;
	cin >> start >> target;
	cout << EditDistance(start, target) << endl;
	return 0;
}