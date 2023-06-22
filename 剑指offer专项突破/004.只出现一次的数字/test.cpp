#include <vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int bitNums[32]{};
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < 32; j++) {
				bitNums[31 - j] += (nums[i] >> j) & 1;
			}
		}
		int res = 0;
		for (int i = 0; i < 32; i++) {
			res = (res << 1) + bitNums[i] % 3;
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> v{2, 2, 3, 2};
	s.singleNumber(v);
}