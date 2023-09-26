#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
	vector<string> findNeighbors(const string& str) {
		vector<string> ret;
		string tmp = str;
		for (auto& ch : tmp) {
			char old = ch;
			for (char i = 'a'; i <= 'z'; i++) {
				if (i != old) {
					ch = i;
					ret.push_back(tmp);
				}
			}
			ch = old; // 变回去
		}
		return ret;
	}
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		// 头尾双向广度搜索
		unordered_set<string> notVisited(wordList.begin(), wordList.end());
		unordered_set<string> front, back;
		if (notVisited.find(endWord) == notVisited.end())
			return 0;
		int length = 2;
		front.insert(beginWord);
		back.insert(endWord);
		// 每次从节点少的方向搜索，保证front的size小于等于back
		while (!front.empty() && !back.empty()) {
			if (back.size() < front.size())
				swap(front, back);
			unordered_set<string> next;
			for (auto& str : front) {
				auto words = findNeighbors(str);
				for (auto& e : words) {
					if (back.find(e) != back.end())
						return length;
					if (notVisited.find(e) != back.end()) {
						notVisited.erase(e);
						next.insert(e);
					}
				}
			}
			length++;
			swap(front, next);
		}
		return 0;
	}
};