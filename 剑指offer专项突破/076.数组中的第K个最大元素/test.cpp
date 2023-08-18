#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	int partition(vector<int>& nums, int start, int end) {
		int key = rand() % (end - start + 1) + start;
		swap(nums[key], nums[end]);
		int big = start - 1;
		for (int i = start; i < end; i++) {
			if (nums[i] > nums[end]) {
				big++;
				swap(nums[big], nums[i]);
			}
		}
		big++;
		swap(nums[big], nums[end]);
		return big;
	}
public:
	int findKthLargest(vector<int>& nums, int k) {
		int start(0), end(nums.size() - 1);
		int i = partition(nums, start, end);
		while (i != k - 1) {
			// 如果返回的中间值大于k-1，则分区左侧
			i > k - 1 ? end = i - 1 : start = i + 1;
			i = partition(nums, start, end);
		}
		return nums[k - 1];
	}
};