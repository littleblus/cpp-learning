#include <vector>
#include <string>
using namespace std;

class Solution {
	bool isSorted(string& a, string& b, int* ord) {
		int i;
		for (i = 0; i < a.size() && i < b.size(); i++) {
			int o1(ord[a[i] - 'a']), o2(ord[b[i] - 'a']);
			if (o1 < o2)
				return true;
			if (o1 > o2)
				return false;
		}
		if (a.size() != b.size() && i == b.size()) {
			return false;
		}
		else {
			return true;
		}
	}
public:
	bool isAlienSorted(vector<string>& words, string order) {
		int ord[26];
		for (int i = 0; i < 26; i++) {
			ord[order[i] - 'a'] = i;
		}
		for (int i = 0; i < words.size() - 1; i++) {
			if (isSorted(words[i], words[i + 1], ord) == false)
				return false;
		}
		return true;
	}
};

int main() {
	Solution s;
	vector<string> v{"hello", "leetcode"};
	s.isAlienSorted(v, "hlabcdefgijkmnopqrstuvwxyz");
	return 0;
}