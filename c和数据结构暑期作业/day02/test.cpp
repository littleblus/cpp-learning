#include <iostream>
#include <unordered_map>
using namespace std;

//第一个只出现一次的字符
//https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=188&&tqId=38575&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		unordered_map<char, int> alphaToCount;
		for (char e : str) {
			alphaToCount[e]++;
		}
		for (int i = 0; i < str.size(); i++) {
			if (alphaToCount[str[i]] == 1)
				return i;
		}
		return -1;
	}
};



//判定字符是否唯一
//https://leetcode.cn/problems/is-unique-lcci/
class Solution {
public:
	bool isUnique(string astr) {
		unordered_map<char, int> alphaToCount;
		for (char e : astr) {
			alphaToCount[e]++;
		}
		for (char e : astr) {
			if (alphaToCount[e] != 1)
				return false;
		}
		return true;
	}
};