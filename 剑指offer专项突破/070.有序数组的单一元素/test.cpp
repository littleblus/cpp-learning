#include <vector>
using namespace std;

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		// 左侧 两数相等 右侧 两数不相等
		int left(0), right(nums.size() / 2);
		while (left <= right) {
			int mid = left + right >> 1;
			int i = mid * 2;
			if (i < nums.size() - 1 && nums[i] != nums[i + 1]) {
				if (mid == 0 || nums[i - 2] == nums[i - 1])
					return nums[i];
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return nums[nums.size() - 1];
	}
};