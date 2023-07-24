#include <vector>
#include <queue>
using namespace std;

// topK
//https://leetcode.cn/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        while (--k) {
            pq.pop();
        }
        return pq.top();
    }
};