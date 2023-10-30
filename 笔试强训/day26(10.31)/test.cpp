#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 跳台阶扩展
class Solution {
public:
    int jumpFloorII(int number) {
		if (number == 1) return 1;
		int res = 1;
        for (int i = 2; i <= number; i++) {
			res *= 2;
		}
		return res;
    }
};



// 快到碗里来
int main() {
	const double PI = 3.14;
	double len, r;
	while (cin >> len >> r) {
		double cir = 2 * PI * r;
		if (len <= cir) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}