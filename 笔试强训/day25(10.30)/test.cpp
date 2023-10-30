#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 星际密码

/*
*	|1 , 1| ^ n   取左上角的值
*	|1 , 0|
*/
string passwd(int n) {
	// 满足斐波那契数列
	// 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610
	string res;
	if (n <= 3) {
		res = to_string(n);
	}
	else {
		int a = 1, b = 1;
		while (--n) {
			int c = (a + b) % 10000;
			a = b;
			b = c;
		}
		res = to_string(b);
	}
	while (res.size() < 4) {
		res = "0" + res;
	}
	return res;
}

int main() {
	int n;
	while (cin >> n) {
		while (n--) {
			int tmp;
			cin >> tmp;
			cout << passwd(tmp);
		}
		cout << endl;
	}
	return 0;
}



// 数根
int main() {
	string s;
	while (cin >> s) {
		do {
			int sum = 0;
			for (auto ch : s) {
				sum += ch - '0';
			}
			s = to_string(sum);
		} while (s.size() > 1);
		cout << s << endl;
	}
	return 0;
}