#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 数组中第 K 个独一无二的字符串
// https://leetcode.cn/problems/kth-distinct-string-in-an-array/description/
class Solution {
public:
	string kthDistinct(vector<string>& arr, int k) {
		int cnt = 0;
		unordered_map<string, int> strToCnt;
		for (auto& str : arr) {
			strToCnt[str]++;
		}
		for (auto& str : arr) {
			if (strToCnt[str] == 1 && ++cnt == k) return str;
			if (cnt > k) return "";
		}
		return "";
	}
};



// 查找共用字符
// https://leetcode.cn/problems/find-common-characters/description/
class Solution {
public:
	vector<string> commonChars(vector<string>& words) {
		array<int, 26> mincnt;
		mincnt.fill(INT_MAX);
		for (auto& str : words) {
			int tmp[26]{};
			for (auto ch : str) {
				tmp[ch - 'a']++;
			}
			for (size_t i = 0; i < 26; i++) {
				mincnt[i] = min(mincnt[i], tmp[i]);
			}
		}
		vector<string> vs;
		for (size_t i = 0; i < 26; i++) {
			int cnt = mincnt[i];
			while (cnt--) {
				vs.emplace_back(1, i + 'a');
			}
		}
		return vs;
	}
};