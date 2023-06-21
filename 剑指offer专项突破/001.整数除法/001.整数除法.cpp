#include <climits>
#include <iostream>
class Solution {
public:
    int divide(int a, int b) {
		//处理溢出
		if (a == INT_MIN && b == -1)
			return INT_MAX;
        //转换为负数除负数
		int flag = 1;
		if (a >= 0) {
			flag = -flag;
			a = -a;
		}
		if (b >= 0) {
			flag = -flag;
			b = -b;
		}
		return flag > 0 ? -dividecore(a, b) : dividecore(a, b);
    }
private:
	int dividecore(const int a, const int b) {
		if (a > b)
			return 0;
		int sum = 0;
		int times = -1;//防止溢出
		int divided = a;//被除数
		int endivide = b;//除数
	again:
		while (divided - endivide <= endivide) {
			endivide += endivide;
			times += times;
		}
		sum += times;//防止溢出
		divided -= endivide;
		endivide = b;//初始化
		times = -1;//初始化
		if (divided <= endivide)
			goto again;
		return sum;
	}
};

int main() {
	Solution s;
	std::cout << s.divide(15, 2) << ' ' << INT_MIN;
}