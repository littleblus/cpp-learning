#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
	void chDecrease(char& ch) {
		if (ch == '0')
			ch = '9';
		else
			ch--;
	}

	void chIncrease(char& ch) {
		if (ch == '9')
			ch = '0';
		else
			ch++;
	}
public:
	int openLock(vector<string>& deadends, string target) {
		if (target == "0000")
			return 0;
		// Ë«Ïòbfs
		unordered_set<string> front, back, visited, dead(deadends.begin(), deadends.end());
		if (dead.count("0000"))
			return -1;
		front.emplace("0000");
		visited.insert("0000");
		back.emplace(target);
		int count = 1;
		while (!front.empty() && !back.empty()) {
			if (back.size() < front.size())
				swap(front, back);
			unordered_set<string> next;
			for (auto& str : front) {
				string tmp = str;
				for (int i = 0; i < 4; i++) {
					chDecrease(tmp[i]);
					if (back.count(tmp))
						return count;
					else if (!dead.count(tmp) && !visited.count(tmp)) {
						next.emplace(tmp);
						visited.insert(tmp);
					}
					chIncrease(tmp[i]);
					chIncrease(tmp[i]);
					if (back.count(tmp))
						return count;
					else if (!dead.count(tmp) && !visited.count(tmp)) {
						next.emplace(tmp);
						visited.insert(tmp);
					}
					chDecrease(tmp[i]);
				}
			}
			count++;
			swap(front, next);
		}
		return -1;
	}
};

int main() {
	Solution sol;
	vector<string> vs{ "0201","0101","0102","1212","2002" };
	sol.openLock(vs, "0202");
	return 0;
}