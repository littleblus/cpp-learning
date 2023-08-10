#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// ����������
//https://leetcode.cn/problems/sorting-the-sentence/

class Solution {
public:
	string sortSentence(string s) {
		vector<string> tmp;
		tmp.push_back("");
		for (auto e : s) { // �ָ��ַ���
			if (e != ' ')
				tmp.back() += e;
			else
				tmp.push_back("");
		}
		vector<string> ret;
		ret.resize(tmp.size());
		for (auto& str : tmp) {
			int pos = str[str.size() - 1] - 1 - '0';
			str.pop_back();
			ret[pos] = str;
		}
		string res;
		for (auto& str : ret) {
			res += str;
			res += ' ';
		}
		res.pop_back();
		return res;
	}
};

//int main() {
//	Solution s;
//	s.sortSentence("is2 sentence4 This1 a3");
//
//	return 0;
//}



// ���г������
//https://leetcode.cn/problems/longest-harmonious-subsequence/

class Solution {
public:
	int findLHS(vector<int>& nums) {
		unordered_map<int, int> numToCount;
		for (auto e : nums) {
			numToCount[e]++;
		}
		int maxRes = 0;
		for (auto e : nums) {
			if (numToCount[e + 1] != 0)
				maxRes = max(numToCount[e] + numToCount[e + 1], maxRes);
		}
		return maxRes;
	}
};