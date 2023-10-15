#include <vector>
#include <string>

using namespace std;

class Solution {
	bool similar(const string& s1, const string& s2) {
		int diff = 0;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) {
				diff++;
			}
		}
		return diff <= 2;
	}

	int findFather(vector<int>& fathers, int i) {
		if (fathers[i] == i) {
			return i;
		}
		fathers[i] = findFather(fathers, fathers[i]);
		return fathers[i];
	}

	bool isUnion(vector<int>& fathers, int i, int j) {
		int fatherI(findFather(fathers, i));
		int fatherJ(findFather(fathers, j));
		if (fatherI != fatherJ) {
			fathers[fatherI] = fatherJ;
			return true;
		}
		return false;
	}
public:
	int numSimilarGroups(vector<string>& strs) {
		vector<int> fathers(strs.size());
		for (size_t i = 0; i < fathers.size(); i++) {
			fathers[i] = i;
		}
		int res = strs.size();
		for (size_t i = 0; i < strs.size(); i++) {
			for (size_t j = i + 1; j < strs.size(); j++) {
				if (similar(strs[i], strs[j]) && isUnion(fathers, i, j)) {
					res--;
				}
			}
		}
		return res;
	}
};

int main() {
	Solution sol;
	vector<string> vs{"blw", "bwl", "wlb"};
	sol.numSimilarGroups(vs);
	return 0;
}