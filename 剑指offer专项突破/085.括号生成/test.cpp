#include <vector>
#include <string>
using namespace std;

class Solution {
	void dfs(int l, int r, string s) {
		if (!l && !r) {
			ret.push_back(s);
			return;
		}
		if (l) {
			dfs(l - 1, r, s + '(');
		}
		if (l < r) {
			dfs(l, r - 1, s + ')');
		}
	}

	vector<string> ret;
public:
	vector<string> generateParenthesis(int n) {
		dfs(n, n, "");
		return ret;
	}
};