#include <vector>
using namespace std;

// 只出现一次的数 ii
//https://leetcode.cn/problems/single-number-ii/description/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (auto e : nums) {
                sum += (e >> i) & 1;
            }
            if (sum % 3 != 0) {
                res |= 1 << i;
            }
        }
        return res;
    }
};