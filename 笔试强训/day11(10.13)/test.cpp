#include <iostream>

using namespace std;

// 寻找最近公共祖先
class LCA {
public:
	int getLCA(int a, int b) {
		// 1   2 3   4 5 6 7
		while (a != b) {
			if (a < b) {
				b /= 2;
			}
			else {
				a /= 2;
			}
		}
		return a;
	}
};



// 求二进制连续1的最大个数
int main() {
	int n;
	cin >> n;
	int res = 0;
	int tmp = 0;
	for (int i = 0; i < 32; i++) {
		if (n & 1)
			tmp++;
		else {
			res = max(tmp, res);
			tmp = 0;
		}
		n >>= 1;
	}
	cout << res << endl;
	return 0;
}