#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int prime[26]{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
		size_t insertPos = 0;
		unordered_map<size_t, size_t> mulToPos;
		vector<vector<string>> res;
		for (auto& e : strs) {
			size_t mul = 1;
			for (auto c : e) {
				mul *= prime[c - 'a'];
			}
			auto it = mulToPos.find(mul);
			if (it == mulToPos.end()) {
				mulToPos.insert({ mul,insertPos });
				res.push_back(vector<string>());
				res[insertPos].push_back(e);
				insertPos++;
			}
			else {
				res[it->second].push_back(e);
			}
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<string> v{ "eat", "tea", "tan", "ate", "nat", "bat" };
	s.groupAnagrams(v);
	return 0;
}