#include <vector>
using namespace std;
class Solution {
public:
	vector<int> countBits(int n) {
		vector<int> ret;
		for (int i = 0; i <= n; i++) {
			int cur = i, sum = 0;
			while (cur) {
				cur = cur & (cur - 1);
				sum++;
			}
			ret.push_back(sum);
		}
		return ret;
	}
};