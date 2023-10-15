#include <iostream>

using namespace std;

// 二进制插入
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		int bits[32]{ 0 };
		int bitpos = 0;
		for (int a = 0; a < i - j + 1; a++) {
			bits[a] = (m >> a) & 1;
		}
		for (int a = j; a <= i; a++) {
			n |= (bits[bitpos++] << a);
		}
		return n;
	}
};



// 查找组成一个偶数最接近的两个素数
bool isPrime(int n) {
	if (n == 2) {
		return true;
	}
	else if (n % 2 != 0) {
		for (int i = 3; i < n; i += 2) {
			if (n % i == 0)
				return false;
		}
		return true;
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	int lit(n / 2), big(n / 2);
	if (!(lit + big == n && isPrime(lit) && isPrime(big))) {
		do {
			if (lit + big > n) {
				while (!isPrime(--lit));
			}
			else {
				while (!isPrime(++big));
			}
		} while (lit + big != n);
	}
	cout << lit << endl << big << endl;
	return 0;
}