#include <iostream>
#include <vector>

using namespace std;

// 只出现一次的数字
//https://leetcode.cn/problems/single-number/description/
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int sum = 0;
		for (auto e : nums) {
			sum ^= e;
		}
		return sum;
	}
};



// 杨辉三角
//https://leetcode.cn/problems/pascals-triangle/description/
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		// 为两侧填充1
		for (int i = 1; i <= numRows; i++) {
			vector<int> tmp;
			for (int j = 0; j < i; j++) {
				tmp.push_back(1);
			}
			ret.push_back(tmp);
		}
		// 计算
		for (int i = 2; i < numRows; i++) {
			for (int j = 1; j < ret[i].size() - 1; j++) {
				ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
			}
		}
		return ret;
	}
};



// 删除有序数组中的重复项
//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int tmp(INT_MAX), sum(0);
		for (auto i = nums.begin(); i != nums.end(); i++) {
			if (*i == tmp) {
				i = nums.erase(i);
				i--;
			}
			else {
				tmp = *i;
				sum++;
			}
		}
		return sum;
	}
};

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int slow(1), fast(1);
		while (fast < nums.size()) {
			if (nums[fast] != nums[fast - 1]) {
				nums[slow++] = nums[fast];
			}
			fast++;
		}
		return slow;
	}
};



// 只出现一次的数字 III
//https://leetcode.cn/problems/single-number-iii/
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int twoxor(0), a(0), b(0), diff;
		for (auto e : nums) {
			twoxor ^= e;
		}
		if (twoxor == INT_MIN)
			diff = twoxor;
		else
			diff = twoxor & (-twoxor);// 取出二进制的最低位的1
		for (auto e : nums) {
			if (e & diff)
				a ^= e;
			else
				b ^= e;
		}
		return { a,b };
	}
};



// 数组中出现次数超过一半的数字
//https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&&tqId=11181&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int>& numbers) {
		int king(numbers[0]), count(0);
		for (auto e : numbers) {
			if (e == king)
				count++;
			else {
				count--;
				if (count == 0) {
					king = e;
					count = 1;
				}
			}
		}
		return king;
	}
};



// 电话号码的字母组合
//https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/、
class Solution {
	const string phone[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> ret;
	string s;

	// 回溯算法
	void dfs(const string& digits, int index) {
		if (index == digits.size()) {
			ret.push_back(s);
			return;
		}
		int letter = digits[index] - '0';
		for (int i = 0; i < phone[letter].size(); i++) {
			s += phone[letter][i];
			dfs(digits, index + 1);
			s.pop_back();
		}
	}
public:
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) {
			return ret;
		}
		dfs(digits, 0);
		return ret;
	}
};