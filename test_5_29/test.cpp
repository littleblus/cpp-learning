#include<iostream>
#include<string>

using namespace std;

//https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&rp=5&ru=/activity/oj&qru=/ta/huawei/question-ranking
// 字符串里面最后一个单词的长度
int main() {
	string s;
	getline(cin, s);
	int pos = s.rfind(' ');
	if (pos == string::npos)
		cout << s.size() << endl;
	else
		cout << s.size() - pos - 1 << endl;
	return 0;
}



//https://leetcode-cn.com/problems/valid-palindrome/
// 验证一个字符串是否是回文
class Solution {
public:
	bool isPalindrome(string s) {
		int pos(0);
		string t;
		while (pos < s.size()) {
			if (isdigit(s[pos]) || isalpha(s[pos])) {
				if (isupper(s[pos]))
					s[pos] = tolower(s[pos]);
				t += s[pos];
			}
			pos++;
		}
		string rt = t;
		reverse(rt.begin(), rt.end());
		return t == rt;
	}
};



//https://leetcode-cn.com/problems/reverse-string-ii/
// 翻转字符串II：区间部分翻转
class Solution {
public:
	string reverseStr(string s, int k) {
		int less = s.size() % (2 * k);
		int n = s.size() / (2 * k);
		for (int i = 0; i < s.size() - less; i += 2 * k) {
			reverse(s.begin() + i, s.begin() + i + k);
		}
		if (less >= k)
			reverse(s.begin() + n * 2 * k, s.begin() + n * 2 * k + k);
		else
			reverse(s.begin() + n * 2 * k, s.end());
		return s;
	}
};



//https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
// 翻转字符串III：翻转字符串中的单词
class Solution {
public:
	string reverseWords(string s) {
		int prev(0), cur(0);
		int back = s.find(' ');
		if (back == string::npos) {
			reverse(s.begin(), s.end());
			return s;
		}
		while (true) {
			reverse(s.begin() + prev, s.begin() + back);
			prev = back + 1;
			back = s.find(' ', prev);
			if (back == string::npos) {
				reverse(s.begin() + prev, s.end());
				break;
			}
		}
		return s;
	}
};



//https://leetcode-cn.com/problems/multiply-strings/description/
// 字符串相乘
class Solution {
public:
	string addStrings(string num1, string num2) {
		int i((int)num1.size() - 1), j((int)num2.size() - 1);
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
		if (carry != 0)//处理残余进位
			ret += '0' + carry;
		reverse(ret.begin(), ret.end());
		//消零
		while (ret.front() == '0' && ret.size() > 1) {
			ret.erase(ret.begin());
		}
		return ret;
	}

	string multiply(string num1, string num2) {
		string ret;
		int len1 = (int)num1.size() - 1;
		int j = (int)num2.size() - 1;
		//用第二个数的每一位依次相乘第一个数整体
		while (j >= 0) {
			int carry(0), k((int)num2.size() - j - 1);//数位
			for (int i = len1; i >= 0; i--) {
				int tmp = (num1[i] - '0') * (num2[j] - '0') + carry;//单数相乘
				carry = tmp / 10;
				tmp %= 10;//进位
				string add;//创建一个带数位的计算结果string
				add += tmp + '0';
				for (int n = k++; n > 0; n--) {
					add += '0';
				}
				ret = addStrings(ret, add);//调用字符串相加
			}
			if (carry != 0) {//处理残余进位
				string add;
				add += carry + '0';
				for (int n = k; n > 0; n--) {
					add += '0';
				}
				ret = addStrings(ret, add);
				carry = 0;
			}
			j--;
		}
		//消零
		while (ret.front() == '0' && ret.size() > 1) {
			ret.erase(ret.begin());
		}
		return ret;
	}
};