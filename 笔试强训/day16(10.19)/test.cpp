#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 完全数
// 除了自身以外的约数和恰好等于他本身
int main() {
	int cnt(0), n(0);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int sum = 1;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				sum += j + i / j;
			}
			if (sum > i)
				break;
		}
		if (sum == i)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}



// 扑克牌大小
enum category {
	个子,
	对子,
	三连,
	炸弹,
	顺子,
	王炸
};

vector<string> cards(const string& hand) {
	vector<string> res;
	res.emplace_back("");
	for (auto ch : hand) {
		if (ch == ' ') {
			res.emplace_back("");
		}
		else {
			res.back().push_back(ch);
		}
	}
	return res;
}

category classify(const vector<string>& cards) {
	if (cards.size() == 1) {
		return 个子;
	}
	else if (cards.size() == 2) {
		if (cards[0] == "joker")
			return 王炸;
		else
			return 对子;
	}
	else if (cards.size() == 3) {
		return 三连;
	}
	else if (cards.size() == 4) {
		return 炸弹;
	}
	else {
		return 顺子;
	}
}

unordered_map<string, int> order{
	{"3", 0},
	{"4", 1},
	{"5", 2},
	{"6", 3},
	{"7", 4},
	{"8", 5},
	{"9", 6},
	{"10", 7},
	{"J", 8},
	{"Q", 9},
	{"K", 10},
	{"A", 11},
	{"2", 12},
	{"joker", 13},
	{"JOKER", 14},
};

int main() {
	string left;
	getline(cin, left);
	auto mid = left.find('-');
	string right(left.begin() + mid + 1, left.end());
	left.resize(mid);
	//cout << left << endl;
	//cout << right << endl;
	vector<string> cardsL(cards(left)), cardsR(cards(right));
	category lc(classify(cardsL)), rc(classify(cardsR));
	if (lc == 王炸) {
		cout << left << endl;
	}
	else if (rc == 王炸) {
		cout << right << endl;
	}
	else if (lc == rc) {
		if (order[cardsL[0]] > order[cardsR[0]]) {
			cout << left << endl;
		}
		else {
			cout << right << endl;
		}
	}
	else {
		if (lc == 炸弹) {
			cout << left << endl;
		}
		else if (rc == 炸弹) {
			cout << right << endl;
		}
		else {
			cout << "ERROR" << endl;
		}
	}
	
	return 0;
}