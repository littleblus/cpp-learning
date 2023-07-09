#include <string>
using namespace std;

// �ַ���ѹ��
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



// ��Խ���
//https://leetcode.cn/problems/exchange-lcci/
class Solution {
public:
	int exchangeBits(int num) {
		//�ֱ���odd(1010),even(0101)���а�λ�룬Ȼ������λ���ƣ�ż��λ����
		int odd(0xaaaaaaaa), even(0x55555555);
		odd &= num;
		odd >>= 1;
		even &= num;
		even <<= 1;
		//�ٽ�odd��even���л�����
		return odd | even;
	}
};