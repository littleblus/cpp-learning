#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// 两句话中的不常见单词
// https://leetcode.cn/problems/uncommon-words-from-two-sentences/submissions/500958864/
class Solution {
	auto core(string str) {
		unordered_map<string, int> map;
		string tmp;
		for (auto ch : str) {
			if (ch == ' ') {
				map[tmp]++;
				tmp.clear();
			}
			else {
				tmp.push_back(ch);
			}
		}
		map[tmp]++;
		return map;
	}
public:
	vector<string> uncommonFromSentences(string s1, string s2) {
		auto map1(core(s1)), map2(core(s2));
		vector<string> vs;
		for (auto& [str, cnt] : map1) {
			if (cnt == 1 && map2.count(str) == 0) vs.push_back(str);
		}
		for (auto& [str, cnt] : map2) {
			if (cnt == 1 && map1.count(str) == 0) vs.push_back(str);
		}
		return vs;
	}
};