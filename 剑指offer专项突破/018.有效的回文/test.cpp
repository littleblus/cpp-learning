#include <string>
using namespace std;
class Solution {
public:
	bool isPalindrome(string s) {
		int pos = 0;
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