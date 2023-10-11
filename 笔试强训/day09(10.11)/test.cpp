#include <iostream>
#include <vector>
using namespace std;

class UnusualAdd {
public:
	int addAB(int A, int B) {
		int carry = 0;
		int res = 0;
		for (int i = 0; i < 32; i++) {
			int bitA = (A >> i) & 1;
			int bitB = (B >> i) & 1;
			int sum = bitA | bitB;
			if (bitA && bitB) {
				if (carry == 0)
					sum = 0;
				else
					sum = 1;
				carry = 1;
			}
			else if (sum == 1 && carry) {
				sum = 0;
			}
			else if (sum == 0 && carry) {
				sum = 1;
				carry = 0;
			}
			res |= (sum << i);
		}
		return res;
	}
};

int M, N;

void dfs(int i, int j, int tarI, int tarJ, int& count) {
	if (i == tarI && j == tarJ) {
		count++;
		return;
	}
	if (j + 1 <= N)
		dfs(i, j + 1, tarI, tarJ, count);
	if (i + 1 <= M)
		dfs(i + 1, j, tarI, tarJ, count);
}

int main() {
	cin >> M >> N;
	int res = 0;
	dfs(0, 0, M, N, res);
	cout << res << endl;
	return 0;
}