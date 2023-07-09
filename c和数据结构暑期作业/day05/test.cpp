#include <string>
using namespace std;

// 字符串压缩
//https://leetcode.cn/problems/compress-string-lcci/
class Solution {
public:
	string compressString(string S) {
		char ch = S[0];
		int count = 0;
		string ret;
		for (size_t i = 0; i < S.size(); i++) {
			if (S[i] != ch) {
				ret += ch;
				ret += to_string(count);
				ch = S[i];
				count = 1;
			}
			else {
				count++;
			}
		}
		ret += ch;
		ret += to_string(count);
		if (ret.size() < S.size())
			return ret;
		else
			return S;
	}
};



// 配对交换
//https://leetcode.cn/problems/exchange-lcci/
class Solution {
public:
	int exchangeBits(int num) {
		//分别与odd(1010),even(0101)进行按位与，然后奇数位左移，偶数位右移
		int odd(0xaaaaaaaa), even(0x55555555);
		odd &= num;
		odd >>= 1;
		even &= num;
		even <<= 1;
		//再将odd与even进行或运算
		return odd | even;
	}
};