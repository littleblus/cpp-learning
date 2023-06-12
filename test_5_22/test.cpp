#include<iostream>
#include<string>
#include<vector>

using namespace std;

//https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
// 字符串转整形数字
class Solution {
public:
	int StrToInt(string str) {
		int ret(0), i(0), sign(1);
		size_t size(str.size());
		if (str.empty())
			return 0;
		if (str[0] == '+' || str[0] == '-') {
			if (str[0] == '-')
				sign = -1;
			i++;
		}
		for (; i < size; i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				ret += (str[i] - '0') * (int)pow(10, size - i - 1);
			}
			else
				return 0;
		}
		return sign * ret;
	}
};



//https://leetcode-cn.com/problems/add-strings/
// 字符串相加
class Solution {
public:
	string addStrings(string num1, string num2) {
		int i(num1.size() - 1), j(num2.size() - 1);
		int sum(0), carry(0);
		string ret;
		while (i >= 0 || j >= 0) {
			int tmp = (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0) + carry;
			if (tmp > 9) {
				carry = tmp / 10;
				tmp %= 10;
			}
			else
				carry = 0;
			ret += '0' + tmp;
			i--, j--;
		}
		if (carry != 0)
			ret += '0' + carry;
		reverse(ret.begin(), ret.end());
		return ret;
	}
};



//https://leetcode.cn/problems/reverse-string/
// 翻转字符串
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i(0), j(s.size() - 1);
        while (i < j) swap(s[i], s[j]), i++, j--;
    }
};



//https://leetcode.cn/problems/first-unique-character-in-a-string/
// 找字符串中第一个只出现一次的字符
class Solution {
public:
	int firstUniqChar(string s) {
		for (int pos = 0; pos < s.size(); pos++) {
			if (s[pos] == '*')
				continue;
			bool uniq = true;
			for (int i = pos + 1; i < s.size(); i++) {
				if (s[i] == s[pos]) {
					s[i] = '*';
					uniq = false;
				}
			}
			if (uniq)
				return pos;
			else
				s[pos] = '*';
		}
		return -1;
	}
};