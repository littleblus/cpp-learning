#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

// 有效的字母异位词
// https://leetcode.cn/problems/valid-anagram/submissions/495090883/
class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> map;
		for (auto ch : s) {
			map[ch]++;
		}
		for (auto ch : t) {
			if (--map[ch] < 0) return false;
		}
		for (auto& [_, val] : map) {
			if (val) return false;
		}
		return true;
	}
};



// 判断字符串的两半是否相似
// https://leetcode.cn/problems/determine-if-string-halves-are-alike/description/
class Solution {
public:
	unordered_set<char> dict{ 'a','e','i','o','u','A','E','I','O','U' };

	void add(unordered_map<char, int>& map, auto begin, auto end, int weight) {
		while (begin != end) {
			if (dict.count(*begin))
				map[*begin] += weight;
			++begin;
		}
	}

	bool halvesAreAlike(string s) {
		unordered_map<char, int> map;
		add(map, s.begin(), s.begin() + s.size() / 2, 1);
		int count1 = 0;
		for (auto& [_, val] : map) {
			count1 += val;
		}
		map.clear();
		add(map, s.begin() + s.size() / 2, s.end(), 1);
		int count2 = 0;
		for (auto& [_, val] : map) {
			count2 += val;
		}
		return count1 == count2;
	}
};