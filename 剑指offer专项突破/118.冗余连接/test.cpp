#include <vector>

using namespace std;

class Solution {
	int findFather(vector<int>& fathers, int i) {
		if (fathers[i] == i)
			return i;
		fathers[i] = findFather(fathers, fathers[i]);
		return fathers[i];
	}

	bool doUnion(vector<int>& fathers, int i, int j) {
		int fatherI = findFather(fathers, i);
		int fatherJ = findFather(fathers, j);
		if (fatherI != fatherJ) {
			fathers[fatherI] = fatherJ;
			return true;
		}
		return false;
	}
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int N = 0;
		for (auto& v : edges) {
			for (int i = 0; i < 2; i++) {
				N = max(N, v[0]);
				N = max(N, v[1]);
			}
		}
		vector<int> fathers(N + 1);
		for (size_t i = 0; i <= N; i++) {
			fathers[i] = i;
		}
		for (auto& v : edges) {
			if (!doUnion(fathers, v[0], v[1]))
				return v;
		}
		return { 0,0 };
	}
};