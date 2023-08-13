#include <vector>
using namespace std;

class Solution {
	vector<int> p;
	int _sum = 0;
public:
	Solution(vector<int>& w) {
		for (auto e : w) {
			_sum += e;
			p.push_back(_sum);
		}
	}

	int pickIndex() {
		int find = rand() % _sum;
		// binary-search
		int left(0), right(p.size() - 1);
		while (left <= right) {
			int mid = left + right >> 1;
			if (p[mid] > find) {
				if (mid == 0 || p[mid - 1] <= find)
					return mid;
				right = mid - 1;
			}
			else
				left = mid + 1;
		}
		return -1;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */