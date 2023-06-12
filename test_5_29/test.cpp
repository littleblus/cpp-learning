#include<iostream>
#include<string>

using namespace std;

//https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&rp=5&ru=/activity/oj&qru=/ta/huawei/question-ranking
// �ַ����������һ�����ʵĳ���
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
// ��֤һ���ַ����Ƿ��ǻ���
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
// ��ת�ַ���II�����䲿�ַ�ת
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
// ��ת�ַ���III����ת�ַ����еĵ���
class Solution {
public:
	string reverseWords(string s) {

	}
};