#include <vector>
using namespace std;
class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int left = 0, right = 0, len = nums.size();
		bool flag = false;
		int sum = nums[left];
		while (true) {
			if (sum < target) {
				right++;
				if (right < nums.size())
					sum += nums[right];
				else
					break;
			}
			else {
				len = right - left + 1 < len ? right - left + 1 : len;
				sum -= nums[left];
				left++;
				flag = true;
			}
		}
		return flag ? len : 0;
	}
};