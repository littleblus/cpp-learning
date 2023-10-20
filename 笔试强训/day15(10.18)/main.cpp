#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 计算二进制下1的个数
int main() {
	int num, cnt;
	while (cin >> num) {
		cnt = 0;
		for (int i = 0; i < 32; i++) {
			cnt += num & 1;
			num >>= 1;
		}
		cout << cnt << endl;
	}
	return 0;
}



// 手套
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int empty(0), lMin(INT_MAX), rMin(INT_MAX), lSum(0), rSum(0);
		for (int i = 0; i < n; i++) {
			if (!left[i] || !right[i])
				empty += left[i] + right[i];
			else {
				lMin = min(left[i], lMin);
				rMin = min(right[i], rMin);
				lSum += left[i];
				rSum += right[i];
			}
		}
		return empty + min(
				// 一侧为主体，把所有种类全拿走的最坏情况
				lSum - lMin + 1,
				rSum - rMin + 1
				)
				+ 1; // 另一侧随便取一只
	}
};