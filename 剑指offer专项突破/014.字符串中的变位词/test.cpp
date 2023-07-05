#include <string>
using namespace std;
class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s2.size() < s1.size())
			return false;
		//数组模拟哈希表
		int hash[26]{ 0 };
		int left(0), right((int)s1.size());
		for (int i = left; i < right; i++) {
			hash[s1[i] - 'a']++;
			hash[s2[i] - 'a']--;
		}
		while (true) {
			if (isZero(hash, 26))
				return true;
			//去掉最左边的字符
			hash[s2[left] - 'a']++;
			//左指针右移
			left++;
			//判断右指针是否到达边界
			if (right != s2.size()) {
				//未到达，右指针右移
				right++;
				//增加最右边的字符
				hash[s2[right - 1] - 'a']--;
			}
			else {
				//到达
				break;
			}
		}
		return false;
	}
private:
	bool isZero(int* arr, size_t n) {
		for (int i = 0; i < n; i++) {
			if (arr[i] != 0)
				return false;
		}
		return true;
	}
};

int main() {
	string s1("ab"), s2("eidbaooo");
	Solution s;
	s.checkInclusion(s1, s2);
	return 0;
}