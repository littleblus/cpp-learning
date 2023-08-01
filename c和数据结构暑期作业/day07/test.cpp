// 阶乘尾数
//https://leetcode.cn/problems/factorial-zeros-lcci/description/
class Solution {
public:
	int trailingZeroes(int n) {
		long long res(0), div(5);
		while (n >= div) {
			res += n / div;
			div *= 5;
		}
		return res;
	}
};



// 取近似值
//https://www.nowcoder.com/practice/3ab09737afb645cc82c35d56a5ce802a?tpId=37&&tqId=21230&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking
#include <iostream>
using namespace std;

int main() {
	double n;
	cin >> n;
	if (n >= (long long)n + 0.5)
		cout << (long long)n + 1 << endl;
	else
		cout << (long long)n << endl;
	return 0;
}