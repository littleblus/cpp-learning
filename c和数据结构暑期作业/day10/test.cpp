#include <vector>
using namespace std;

// 搜索旋转排序数组
//https://leetcode.cn/problems/search-in-rotated-sorted-array/

class Solution {
	int _core(vector<int>& nums, int target, int left, int right) {
		if (left > right)
			return -1;
		int bisLeft, bisRight, ret;
		int i = (left + right) / 2;
		if (nums[i] <= nums[right]) {
			// 右部分有序
			bisLeft = i;
			bisRight = right;
			ret = _core(nums, target, left, i - 1);
		}
		else {
			bisLeft = left;
			bisRight = i;
			ret = _core(nums, target, i + 1, right);
		}
		// 二分查找
		while (bisLeft <= bisRight) {
			int mid = (bisLeft + bisRight) / 2;
			if (nums[mid] > target) {
				bisRight = mid - 1;
			}
			else if (nums[mid] < target) {
				bisLeft = mid + 1;
			}
			else {
				return mid;
			}
		}
		// 走到这了就是在二分里没找到
		if (ret != -1)
			return ret;
		else
			return -1;
	}
public:
	int search(vector<int>& nums, int target) {
		// 分治法 整个数组取中间部分断开，其中一半是有序的，另一半是无序的
		// 有序的部分进行二分查找，无序的部分的一半是有序的，另一半是无序的
		// 无序部分递归进行调用
		return _core(nums, target, 0, nums.size() - 1);
	}
};



// 二进制链表转整数
//https://leetcode.cn/problems/convert-binary-number-in-a-linked-list-to-integer/

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	int getDecimalValue(ListNode* head) {
		int ret = 0;
		// 遍历链表
		ListNode* cur = head;
		while (cur) {
			ret = (ret << 1) + cur->val;
			cur = cur->next;
		}
		return ret;
	}
};