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

	}
};