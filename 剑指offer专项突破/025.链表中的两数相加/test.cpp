#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// 进阶：不反转输入链表
		// 解决方法：将每个数字依次压入栈中
		stack<int> num1, num2;
		while (l1) {
			num1.push(l1->val);
			l1 = l1->next;
		}
		while (l2) {
			num2.push(l2->val);
			l2 = l2->next;
		}
		ListNode* guard(new ListNode), * cur(guard);
		int carry = 0;
		while (!(num1.empty() && num2.empty())) {
			int t1(0), t2(0);
			if (!num1.empty()) {
				t1 = num1.top();
				num1.pop();
			}
			if (!num2.empty()) {
				t2 = num2.top();
				num2.pop();
			}
			ListNode* newNode = new ListNode((t1 + t2 + carry) % 10);
			carry = (t1 + t2 + carry) / 10;
			cur->next = newNode;
			cur = cur->next;
		}
		// 清空进位
		if (carry) {
			ListNode* newNode = new ListNode(1);
			carry = 0;
			cur->next = newNode;
			cur = cur->next;
		}
		ListNode* ret = guard->next;
		delete guard;
		// 反转返回的链表
		cur = ret;
		ListNode* prev = nullptr;
		while (cur) {
			ListNode* next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}
};