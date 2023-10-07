#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
	bool startWith(const string& longstr, const string& shortstr) {
		if (longstr.size() == shortstr.size())
			return false;
		size_t i(0), j(0);
		while (j < shortstr.size()) {
			if (longstr[i++] != shortstr[j++])
				return false;
		}
		return true;
	}
public:
	string alienOrder(vector<string>& words) {
		unordered_map<char, unordered_set<char>> graph;
		unordered_map<char, int> inDegrees;
		for (auto& str : words) {
			for (char ch : str) {
				graph.emplace(ch, unordered_set<char>());
				inDegrees.emplace(ch, 0);
			}
		}
		for (size_t i = 1; i < words.size(); i++) {
			string& s1(words[i - 1]), & s2(words[i]);
			if (startWith(s1, s2))
				return "";
			for (size_t j = 0; j < s1.size() && j < s2.size(); j++) {
				char ch1(s1[j]), ch2(s2[j]);
				if (ch1 != ch2) {
					if (graph[ch1].count(ch2) == 0) {
						graph[ch1].emplace(ch2);
						++inDegrees[ch2];
					}
					break;
				}
			}
		}
		queue<char> que;
		for (auto& e : inDegrees) {
			if (e.second == 0) {
				que.emplace(e.first);
			}
		}
		string ret;
		while (!que.empty()) {
			char ch = que.front();
			que.pop();
			ret.push_back(ch);
			for (char next : graph[ch]) {
				--inDegrees[next];
				if (inDegrees[next] == 0)
					que.emplace(next);
			}
		}
		return ret.size() == graph.size() ? ret : "";
	}
};

int main() {
	Solution sol;
	vector<string> vs{ "wrt","wrf","er","ett","rftt","te" };
	sol.alienOrder(vs);
}