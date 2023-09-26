#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int A, B, C;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((a + c) % 2 != 0) {
		cout << "No" << endl;
		return 0;
	}
	A = (a + c) / 2;
	B = A - a;
	C = d - B;
	if (A < 0 || B < 0 || C < 0) {
		cout << "No" << endl;
		return 0;
	}
	cout << A << ' ' << B << ' ' << C << endl;
	return 0;
}

int main() {
	int n, base;
	cin >> n >> base;
	string res;
	int i;
	bool flag = false;
	if (n == 0) {
		cout << "0" << endl;
		return 0;
	}
	if (n < 0) {
		n = -n;
		flag = true;
	}
	for (i = 0; n > pow(base, i); i++);
	// cout << i << endl;
	for (int j = i - 1; j >= 0; j--) {
		int minus = pow(base, j);
		if (n >= minus) {
			int count = 0;
			do {
				n -= minus;
				count++;
			} while (n >= minus);
			if(count < 10)
				res.push_back(count + '0');
			else
				res.push_back(count - 10 + 'A');
		}
		else {
			res.push_back('0');
		}
	}
	if (flag)
		cout << '-' << res << endl;
	else
		cout << res << endl;
	return 0;
}