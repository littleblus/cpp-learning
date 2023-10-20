#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 杨辉三角的变化
int main() {
	int n;
	cin >> n;
	if (n < 3) {
		cout << -1;
	}
	else if (n % 4 == 1 || n % 4 == 3) {
		cout << 2;
	}
	else if (n % 4 == 2) {
		cout << 4;
	}
	else {
		cout << 3;
	}
	cout << endl;
	return 0;
}



// 计算某字符出现次数
int main() {
	string line;
	char ch;
	getline(cin, line);
	cin >> ch;
	bool plus = ch <= 'Z';
	bool isch = isalpha(ch);
	//cout << isch << endl;
	int cnt = 0;
	for (auto e : line) {
		if (isch) {
			if (plus) {
				if (e == ch || e == ch + 32) {
					cnt++;
				}
			}
			else {
				if (e == ch || e == ch - 32) {
					cnt++;
				}
			}
		}
		else {
			if (e == ch) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}