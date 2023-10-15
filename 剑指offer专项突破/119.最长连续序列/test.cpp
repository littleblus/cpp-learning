#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
	int findFather(unordered_map<int, int>& fathers, int i) {
		if (fathers[i] == i)
			return i;
		int newFather = findFather(fathers, fathers[i]);
		fathers[i] = newFather;
		return newFather;
	}

	void doUnion(
		unordered_map<int, int>& fathers,
		unordered_map<int, int>& counts,
		int i, int j) {
		int fatherI = findFather(fathers, i);
		int fatherJ = findFather(fathers, j);
		if (fatherI != fatherJ) {
			fathers[fatherI] = fatherJ;
			counts[fatherJ] += counts[fatherI];
		}
	}
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> fathers, counts;
		unordered_set<int> all;
		for (int e : nums) {
			fathers[e] = e;
			counts[e] = 1;
			all.emplace(e);
		}
		for (int e : nums) {
			if (all.count(e - 1)) {
				doUnion(fathers, counts, e, e - 1);
			}
			if (all.count(e + 1)) {
				doUnion(fathers, counts, e, e + 1);
			}
		}
		int res = 0;
		for (auto& e : counts) {
			res = max(e.second, res);
		}
		return res;
	}
};