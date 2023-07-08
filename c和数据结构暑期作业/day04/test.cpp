#include <iostream>
#include <string>
using namespace std;

//µ¥´ÊËõÐ´
//https://www.nowcoder.com/practice/af2c953f9fc8464fa0e3252da8eb4131?tpId=182&&tqId=34861&rp=1&ru=/ta/exam-all&qru=/ta/exam-all/question-ranking
int main() {
	string s;
	int n;
	cin >> n;
	while (--n >= 0) {
		cin >> s;
		if (s.size() >= 10) {
			int len = s.size() - 2;
			string t;
			t += s[0];
			t += to_string(len);
			t += s[s.size() - 1];
			s = t;
		}
		cout << s << endl;
	}
	return 0;
}



//URL»¯
//https://leetcode.cn/problems/string-to-url-lcci/
class Solution {
public:
	string replaceSpaces(string S, int length) {
		int i = 0;
		string ret;
		while (--length >= 0) {
			if (S[i] == ' ') {
				ret += "%20";
			}
			else {
				ret += S[i];
			}
			i++;
		}
		return ret;
	}
};