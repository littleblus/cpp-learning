#include <vector>
#include <string>
using namespace std;

class Solution {
	bool isPalindrome(string& str, int beg, int end) {
		while (beg < end) {
			if (str[beg++] != str[end--])
				return false;
		}
		return true;
	}

	void dfs(string& str, int i) {
		if (i == str.size()) {
			ret.push_back(cur);
		}
		else {
			for (int j = i + 1; j <= str.size(); j++) {
				if (isPalindrome(str, i, j - 1)) {
					cur.push_back(string(str.begin() + i, str.begin() + j));
					dfs(str, j);
					cur.pop_back();
				}
			}
		}
	}

	vector<string> cur;
	vector<vector<string>> ret;
public:
	vector<vector<string>> partition(string s) {
		dfs(s, 0);
		return ret;
	}
};