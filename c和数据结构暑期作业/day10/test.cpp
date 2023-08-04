#include <vector>
using namespace std;

// ������ת��������
//https://leetcode.cn/problems/search-in-rotated-sorted-array/

class Solution {
	int _core(vector<int>& nums, int target, int left, int right) {
		if (left > right)
			return -1;
		int bisLeft, bisRight, ret;
		int i = (left + right) / 2;
		if (nums[i] <= nums[right]) {
			// �Ҳ�������
			bisLeft = i;
			bisRight = right;
			ret = _core(nums, target, left, i - 1);
		}
		else {
			bisLeft = left;
			bisRight = i;
			ret = _core(nums, target, i + 1, right);
		}
		// ���ֲ���
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
		// �ߵ����˾����ڶ�����û�ҵ�
		if (ret != -1)
			return ret;
		else
			return -1;
	}
public:
	int search(vector<int>& nums, int target) {
		// ���η� ��������ȡ�м䲿�ֶϿ�������һ��������ģ���һ���������
		// ����Ĳ��ֽ��ж��ֲ��ң�����Ĳ��ֵ�һ��������ģ���һ���������
		// ���򲿷ֵݹ���е���
		return _core(nums, target, 0, nums.size() - 1);
	}
};



// ����������ת����
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
		// ��������
		ListNode* cur = head;
		while (cur) {
			ret = (ret << 1) + cur->val;
			cur = cur->next;
		}
		return ret;
	}
};