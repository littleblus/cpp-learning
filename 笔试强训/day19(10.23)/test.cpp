#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 汽水瓶
int main() {
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		else {
			int res = 0;
			while (n >= 3) {
				res += n / 3;
				n = n % 3 + n / 3;
			}
			switch (n) {
			case 0:
			case 1:
				cout << res << endl;
				break;
			case 2:
				cout << res + 1 << endl;
				break;
			}
		}
	}
	return 0;
}



// 寻找字符串ab的最长公共子串
int main() {
	string a, b, res;
	cin >> a >> b;
	if (a.size() > b.size())
		swap(a, b);
	for (int i = 0; i < a.size(); i++) {
		for (int sz = a.size() - i; sz > res.size(); sz--) {
			auto pos = b.find(a.substr(i, sz));
			if (pos != string::npos) {
				res = b.substr(pos, sz);
			}
		}
	}
	cout << res << endl;
	return 0;
}