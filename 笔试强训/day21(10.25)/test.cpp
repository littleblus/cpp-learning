#include <iostream>
#include <vector>
using namespace std;

// 洗牌
int main() {
	int rounds;
	cin >> rounds;
	while (rounds--) {
		int n, k;
		cin >> n >> k;
		vector<int> cards(2 * n);
		for (int i = 0; i < 2 * n; i++) {
			cin >> cards[i];
		}
		while (k--) {
			vector<int> left(cards.begin(), cards.begin() + n), right(cards.begin() + n, cards.end());
			for (int i = 0; i < n; i++) {
				cards[2 * i] = left[i];
				cards[2 * i + 1] = right[i];
			}
		}
		for (auto& e : cards) {
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}



// MP3光标位置
#include <list>
int main() {
	int cur(1), n;
	cin >> n;
	char command;
	list<int> songs;
	for (int i = 0; i < n; i++) {
		songs.push_back(i + 1);
	}
	while (cin >> command) {
		if (command == 'U') {
			// 维护坐标
			if (cur == 1) {
				cur = n;
			}
			else {
				cur--;
			}
			// 维护列表
			if (n > 4) {
				if (cur == n) {
					songs.clear();
					for (int i = n - 3; i <= n; i++) {
						songs.push_back(i);
					}
				}
				else if (cur < songs.front()) {
					songs.pop_back();
					songs.push_front(cur);
				}
			}
		}
		else {
			if (cur == n) {
				cur = 1;
			}
			else {
				cur++;
			}
			if (n > 4) {
				if (cur == 1) {
					songs.clear();
					for (int i = 1; i <= 4; i++) {
						songs.push_back(i);
					}
				}
				else if (cur > songs.back()) {
					songs.pop_front();
					songs.push_back(cur);
				}
			}
		}
	}
	for (auto& e : songs) {
		cout << e << " ";
	}
	cout << endl;
	cout << cur << endl;
	return 0;
}