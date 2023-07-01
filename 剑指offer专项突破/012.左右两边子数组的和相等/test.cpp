#include <vector>
using namespace std;
class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int suml(0), sumr(0), i(0);
		for (int e : nums) {
			sumr += e;
		}
		sumr -= nums[0];
		//和均不包含下标i指向的数字本身
		bool flag(false);
		while (suml != sumr && i < nums.size() - 1) {
			i++;
			suml += nums[i - 1];
			sumr -= nums[i];
			if (suml == sumr)
				flag = true;
		}
		if (flag || i == 0)
			return i;
		else
			return -1;
	}
};

int main() {
	Solution s;
	vector<int>t{ 3, -1, 1, -3, 1 };
	s.pivotIndex(t);
	return 0;
}