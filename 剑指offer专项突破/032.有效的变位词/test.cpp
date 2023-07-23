#include <string>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;
		if (s == t)
			return false;
		int dict[256]{ 0 };
		for (char e : s) {
			dict[e]++;
		}
		for (char e : t) {
			if (--dict[e] < 0)
				return false;
		}
		return true;
	}
};

int main() {
	Solution s;
	s.isAnagram("rat", "car");
	return 0;
}