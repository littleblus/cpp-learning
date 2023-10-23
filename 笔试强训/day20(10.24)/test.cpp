#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

// 反转字符串
int main() {
	string s;
	cin >> s;
	for (auto it = s.rbegin(); it != s.rend(); ++it) {
		cout << *it;
	}
	cout << endl;
	return 0;
}



// 公共子串计算
int main() {
	string a, b;
	cin >> a >> b;
	size_t res = 0;
	if (a.size() > b.size()) swap(a, b);
	for (size_t i = 0; i < a.size(); i++) {
		for (size_t j = 1; j <= a.size() - i; j++) {
			auto pos = b.find(a.substr(i, j));
			if (pos != string::npos) res = max(res, j);
		}
	}
	cout << res << endl;
	return 0;
}