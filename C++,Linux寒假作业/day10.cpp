#include <vector>
#include <cstdint>

using namespace std;

// 数组中只出现一次的数
// https://www.nowcoder.com/practice/5d3d74c3bf7f4e368e03096bb8857871?tpId=188&&tqId=38592&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
class Solution {
public:
	int foundOnceNumber(vector<int>& arr, int k) {
		int bit[32]{};
		for (auto num : arr) {
			for (int i = 0; i < 32; i++) {
				bit[i] += (num >> i) & 1;
			}
		}
		int res = 0;
		for (int i = 0; i < 32; i++) {
			if (bit[i] % k) {
				res += (1 << i);
			}
		}
		return res;
	}
};



// 颠倒二进制位
// https://leetcode.cn/problems/reverse-bits/
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		for (int i = 0; i < 32; i++) {
			res += ((n >> i) & 1) << (31 - i);
		}
		return res;
	}
};