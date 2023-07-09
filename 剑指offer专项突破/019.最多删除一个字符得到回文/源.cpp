#include <string>
using namespace std;
class Solution {
public:
	bool validPalindrome(string s) {
		int left(0), right(s.size() - 1);
		while (left < right) {
			if (s[left] != s[right]) {
				string s1, s2;
				s1 = s2 = s;
				s1.erase(left, 1), s2.erase(right, 1);
				return isPAlindrome(s1) || isPAlindrome(s2);
			}
			left++, right--;
		}
		return true;
	}
private:
	bool isPAlindrome(string s) {
		int left(0), right(s.size() - 1);
		while (left < right) {
			if (s[left++] != s[right--])
				return false;
		}
		return true;
	}
};

int main() {
	Solution s;
	s.validPalindrome("abc");
	return 0;
}