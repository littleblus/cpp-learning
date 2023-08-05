#include "链表调试.h"
#include <unordered_map>
using namespace std;

// 表内指定区间反转
//https://www.nowcoder.com/practice/b58434e200a648c589ca2063f1faf58c?tpId=188&&tqId=38555&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		// m开始位置，n结束位置，均为闭区间
		n = n - m + 1; // 反转的个数
		ListNode* prev(nullptr), * cur(head);
		while (cur && --m) {
			prev = cur;
			cur = cur->next;
		}
		//										 nullptr
		//											^
		//											|
		// prev为前一个节点，cur为开始反转的节点 prev->反转尾<-反转头 rear
		ListNode* revPrev(nullptr);
		while (cur && n--) {
			ListNode* next = cur->next;
			cur->next = revPrev;
			revPrev = cur;
			cur = next;
		}
		// 现在cur要么是rear，要么为空
		// revPrev是反转头
		ListNode* tail(nullptr);
		if (prev) {// prev可能是空
			tail = prev->next;
			prev->next = revPrev;
			tail->next = cur; // 是否为空不影响
			return head;
		}
		else {
			// 反转尾是head
			head->next = cur;
			return revPrev;
		}
	}
};



// 从链表中删去总和值为零的连续节点
//https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

class Solution {
public:
	ListNode* removeZeroSumSublists(ListNode* head) {
		// 哈希表保存前缀和
		unordered_map<int, ListNode*> sumToNode;
		ListNode* guard(new ListNode(0, head)), * cur(guard);
		int sum = 0;
		while (cur) {
			sum += cur->val;
			sumToNode[sum] = cur;
			cur = cur->next;
		}
		sum = 0;
		cur = guard;
		while (cur) { // 结点next指向相同前缀和的next
			sum += cur->val;
			cur->next = sumToNode[sum]->next;
			cur = cur->next;
		}
		ListNode* ret = guard->next;
		delete guard;
		return ret;
	}
};