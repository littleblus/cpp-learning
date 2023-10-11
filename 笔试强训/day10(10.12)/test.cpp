#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 井字棋
class Board {
public:
	bool checkWon(vector<vector<int>> board) {
		for (int i = 0; i < board.size(); i++) {
			bool win = true;
			for (int j = 0; j < board.size(); j++) {
				if (board[i][j] != 1) {
					win = false;
					break;
				}
			}
			if (win)
				return true;
		}
		for (int i = 0; i < board.size(); i++) {
			bool win = true;
			for (int j = 0; j < board.size(); j++) {
				if (board[j][i] != 1) {
					win = false;
					break;
				}
			}
			if (win)
				return true;
		}
		bool win = true;
		for (int i = 0; i < board.size(); i++) {
			if (board[i][i] != 1) {
				win = false;
				break;
			}
		}
		if (win)
			return true;
		win = true;
		for (int i = 0; i < board.size(); i++) {
			if (board[i][board.size() - 1 - i] != 1) {
				win = false;
				break;
			}
		}
		if (win)
			return true;
		return false;
	}
};

int getLen(const string& pwd) {
	if (pwd.size() <= 4)
		return 5;
	else if (pwd.size() <= 7)
		return 10;
	else
		return 25;
}

int check(const string& pwd) {
	bool noCh(true), allDown(true), allUp(true);
	int numCnt(0), markCnt(0);
	for (auto ch : pwd) {
		if ('a' <= ch && ch <= 'z') {
			noCh = false;
			allUp = false;
		}
		else if ('A' <= ch && ch <= 'Z') {
			noCh = false;
			allDown = false;
		}
		else if ('0' <= ch && ch <= '9') {
			numCnt++;
		}
		else if ((0x21 <= ch && ch <= 0x2f) || 
			(0x3a <= ch && ch <= 0x40) ||
			(0x5b <= ch && ch <= 0x60) ||
			(0x7b <= ch && ch <= 0x7e)) {
			markCnt++;
		}
	}
	int score = 0;
	if (!noCh) {
		if ((allDown && !allUp) || (!allDown && allUp))
			score += 10;
		else
			score += 20;
	}
	if (numCnt == 1)
		score += 10;
	else if (numCnt > 1)
		score += 20;
	if (markCnt == 1)
		score += 10;
	else if (markCnt > 1)
		score += 25;
	if (!allDown && !allUp && !noCh && numCnt && markCnt)
		score += 5;
	else if (!noCh && numCnt && markCnt)
		score += 3;
	else if (!noCh && numCnt)
		score += 2;
	return score;
}

// 密码强度等级
int main() {
	string pwd;
	cin >> pwd;
	int len = getLen(pwd);
	int alpha = check(pwd);
	int score = len + alpha;
	if (score >= 90)
		cout << "VERY_SECURE" << endl;
	else if(score >= 80)
		cout << "SECURE" << endl;
	else if (score >= 70)
		cout << "VERY_STRONG" << endl;
	else if (score >= 60)
		cout << "STRONG" << endl;
	else if (score >= 50)
		cout << "AVERAGE" << endl;
	else if (score >= 25)
		cout << "WEAK" << endl;
	else
		cout << "VERY_WEAK" << endl;
	return 0;
}