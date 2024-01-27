#include <vector>

using namespace std;

// 两数之和 II - 输入有序数组
// https://leetcode.cn/problems/kLl5u1/description/
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int l(0), r(numbers.size() - 1);
		while (l < r) {
			int sum = numbers[l] + numbers[r];
			if (sum < target) l++;
			else if (sum > target) r--;
			else break;
		}
		vector<int> ret{ l,r };
		return ret;
	}
};



// 数组中出现次数超过一半的数字
// https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&&tqId=11181&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int>& numbers) {
		int king = numbers.front();
		int cnt = 0;
		for (auto e : numbers) {
			if (e == king) cnt++;
			else if (--cnt == 0) king = e, cnt = 1;
		}
		return king;
	}
};