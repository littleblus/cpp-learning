#include <vector>
#include <queue>
#include <string>

using namespace std;

// 矩阵中战斗力最弱的 K 行
// https://leetcode.cn/problems/the-k-weakest-rows-in-a-matrix/description/
class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		// greater
		auto cmp = [](const pair<int, int> l, const pair<int, int> r) {
			return l.first == r.first ? l.second > r.second : l.first > r.first;
			};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
		for (size_t i = 0; i < mat.size(); i++) {
			int cnt = 0;
			for (auto e : mat[i]) {
				if (e) cnt++;
				else break;
			}
			que.emplace(cnt, i);
		}
		vector<int> res;
		while (k--) {
			auto tmp = que.top();
			que.pop();
			res.push_back(tmp.second);
		}
		return res;
	}
};



// 分割平衡字符串
// https://leetcode.cn/problems/split-a-string-in-balanced-strings/description/
class Solution {
public:
	int balancedStringSplit(string s) {
		int pos(0), cnt(0), res(0);
		while (pos < s.size()) {
			if (s[pos] == 'L') cnt++;
			else cnt--;
			if (cnt == 0) res++;
			pos++;
		}
		return res;
	}
};