#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// ��ȫ��
// �������������Լ����ǡ�õ���������
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



// �˿��ƴ�С
enum category {
	����,
	����,
	����,
	ը��,
	˳��,
	��ը
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
		return ����;
	}
	else if (cards.size() == 2) {
		if (cards[0] == "joker")
			return ��ը;
		else
			return ����;
	}
	else if (cards.size() == 3) {
		return ����;
	}
	else if (cards.size() == 4) {
		return ը��;
	}
	else {
		return ˳��;
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
	if (lc == ��ը) {
		cout << left << endl;
	}
	else if (rc == ��ը) {
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
		if (lc == ը��) {
			cout << left << endl;
		}
		else if (rc == ը��) {
			cout << right << endl;
		}
		else {
			cout << "ERROR" << endl;
		}
	}
	
	return 0;
}