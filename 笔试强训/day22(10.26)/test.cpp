#include <iostream>
#include <vector>
using namespace std;

// 小易的升级之路
int main() {
	int n, a;
	while (cin >> n >> a) {
		vector<int> monster(n);
		for (int i = 0; i < n; i++) {
			cin >> monster[i];
		}
		for (int i = 0; i < n; i++) {
			if (monster[i] <= a) {
				a += monster[i];
			}
			else {
				// 求最大公约数
				int x = monster[i];
				int y = a;
				while (x && y) {
					int tmp = x % y;
					x = y;
					y = tmp;
				}
				a += x;
			}
		}
		cout << a << endl;
	}
	return 0;
}



// 找出字符串中第一个只出现一次的字符
#include <string>
int main() {
	string s;
	cin >> s;
	int hash[256] = { 0 };
	for (int i = 0; i < s.size(); i++) {
		hash[s[i]]++;
	}
	bool exist = false;
	for (int i = 0; i < s.size(); i++) {
		if (hash[s[i]] == 1) {
			cout << s[i] << endl;
			exist = true;
			break;
		}
	}
	// 不存在输出-1
	if (!exist) {
		cout << -1 << endl;
	}
	return 0;
}