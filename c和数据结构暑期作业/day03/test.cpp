#include <string>
using namespace std;

//判定是否为字符重排
//https://leetcode.cn/problems/check-permutation-lcci/
class Solution {
public:
	bool CheckPermutation(string s1, string s2) {
		if (s1.size() != s2.size())
			return false;
		int hash[26]{ 0 };
		for (char e : s1) {
			hash[e - 'a']++;
		}
		for (char e : s2) {
			hash[e - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (hash[i] != 0)
				return false;
		}
		return true;
	}
};



//回文排列
//https://leetcode.cn/problems/palindrome-permutation-lcci/
class Solution {
public:
	bool canPermutePalindrome(string s) {
		int hash[128]{ 0 };
		int oddSum = 0;
		for (char e : s) {
			hash[e]++;
		}
		for (int i = 0; i < 128; i++) {
			if (hash[i] % 2 != 0)
				oddSum++;
		}
		if (oddSum <= 1)
			return true;
		else
			return false;
	}
};

int main() {
	string t("AaBb//a");
	Solution s;
	s.canPermutePalindrome(t);
	return 0;
}