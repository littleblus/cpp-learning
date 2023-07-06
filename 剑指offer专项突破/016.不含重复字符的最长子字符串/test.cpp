#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int left(0), right(0), longest(0), hash[128]{ 0 };
		hash[s[0]]++;
		while (right < s.size()) {
			//ÅÐ¶ÏÊÇ·ñÖØ¸´
			bool rep = false;
			for (int i = 0; i < 128; i++) {
				if (hash[i] > 1) {
					rep = true;
					break;
				}
			}
			if (rep) {
				hash[s[left]]--;
				left++;
			}
			else {
				longest = max(right - left + 1, longest);
			}
			right++;
			hash[s[right]]++;
		}
		return longest;
	}
};

int main() {
	string t("pwwkew");
	Solution s;
	s.lengthOfLongestSubstring(t);
	return 0;
}