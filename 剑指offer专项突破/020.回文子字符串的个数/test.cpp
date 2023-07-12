#include <string>
#include <iostream>
using namespace std;

class Solution {
	int countPalin(const string& s, int left, int right) {
		if (s[left] != s[right])
			return 0;
		int ret = 0;
		while (left >= 0 && right < s.size()) {
			if (s[left] == s[right])
				ret++;
			else
				break;
			left--, right++;
		}
		return ret;
	}
public:
	int countSubstrings(string s) {
		int count = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			count += countPalin(s, i, i);
			count += countPalin(s, i, i + 1);
		}
		count += countPalin(s, s.size() - 1, s.size() - 1);
		return count;
	}
};

int main() {
	Solution s1;
	cout << s1.countSubstrings("aaa") << endl;
	return 0;
}