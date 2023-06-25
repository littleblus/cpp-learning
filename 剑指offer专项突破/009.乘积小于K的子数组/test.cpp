#include <vector>
using namespace std;
class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int left = 0, product = 1, count = 0;
		for (int right = 0; right < nums.size(); right++) {
			product *= nums[right];
			while (left <= right && product >= k) {
				product /= nums[left++];
			}
			count += right - left + 1;
		}
		return count;
	}
};