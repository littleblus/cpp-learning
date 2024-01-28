#include <vector>

using namespace std;

// 按奇偶排序数组 II
// https://leetcode.cn/problems/sort-array-by-parity-ii/description/
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& nums) {
		int i(0), j(1);
		for (;;) {
			while (i < nums.size() && nums[i] % 2 == 0) i += 2;
			while (j < nums.size() && nums[j] % 2 != 0) j += 2;
			if (i < nums.size() && j < nums.size())
				swap(nums[i], nums[j]);
			else
				break;
		}
		return nums;
	}
};



// 连续子数组的最大和
// https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=2
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int>& array) {
		int dp;
		int res = array[0];
		for (auto e : array) {
			dp = max(dp + e, e);
			res = max(res, dp);
		}
		return res;
	}
};