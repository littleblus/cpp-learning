#include <vector>
#include <iostream>
using namespace std;

// 一维数组的动态和
//https://leetcode.cn/problems/running-sum-of-1d-array/

class Solution {
public:
	vector<int> runningSum(vector<int>& nums) {
		vector<int> v;
		long long sum = 0;
		for (int e : nums) {
			sum += e;
			v.push_back(sum);
		}
		return v;
	}
};



// 搜索插入位置
//https://leetcode.cn/problems/search-insert-position/
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		// 二分
		int left(0), right(nums.size() - 1);
		int mid = (left + right) / 2;
		while (left <= right) {
			mid = (left + right) / 2;
			int midVal = nums[mid];
			if (target > midVal)
				left = mid + 1;
			else if (target < midVal)
				right = mid - 1;
			else // 相等
				break;
		}
		if (left > right) {
			if (left == nums.size() - 1 && target > nums[left])
				left++;
			mid = left;
			nums.insert(nums.begin() + left, target);
		}
		return mid;
	}
};