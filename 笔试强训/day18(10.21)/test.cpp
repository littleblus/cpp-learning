#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 统计每个月兔子的总数
int main() {
	int prev(1), cur(1);
	int N;
	cin >> N;
	if (N < 3) {
		cout << cur << endl;
	}
	else {
		N -= 2;
		while (N--) {
			int tmp = cur;
			cur += prev;
			prev = tmp;
		}
		cout << cur << endl;
	}
	return 0;
}



// 字符串通配符
//?*Bc*?
//abcd

bool match(const char* s1, const char* s2) {
	if (*s1 == '\0' && *s2 == '\0')
		return true;
	if (*s1 == '\0' || *s2 == '\0')
		return false;
	if (tolower(*s1) == tolower(*s2)) {
		return match(s1 + 1, s2 + 1);
	}
	else {
		if (*s1 == '*') {
			while (*s1 == '*') {
				s1++;
			}
			s1--;
			if (isalnum(*s2)) {
				bool one = match(s1 + 1, s2 + 1);
				bool more = match(s1, s2 + 1);
				return match(s1 + 1, s2) || one || more;
			}
			else {
				return match(s1 + 1, s2);
			}
		}
		else if (*s1 == '?') {
			if (!isalnum(*s2)) {
				return false;
			}
			else {
				return match(s1 + 1, s2 + 1);
			}
		}
		else {
			return false;
		}
	}
}

int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	if (match(s1.c_str(), s2.c_str())) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	return 0;
}