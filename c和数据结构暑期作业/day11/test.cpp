#include "�������.h"
#include <unordered_map>
using namespace std;

// ����ָ�����䷴ת
//https://www.nowcoder.com/practice/b58434e200a648c589ca2063f1faf58c?tpId=188&&tqId=38555&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		// m��ʼλ�ã�n����λ�ã���Ϊ������
		n = n - m + 1; // ��ת�ĸ���
		ListNode* prev(nullptr), * cur(head);
		while (cur && --m) {
			prev = cur;
			cur = cur->next;
		}
		//										 nullptr
		//											^
		//											|
		// prevΪǰһ���ڵ㣬curΪ��ʼ��ת�Ľڵ� prev->��תβ<-��תͷ rear
		ListNode* revPrev(nullptr);
		while (cur && n--) {
			ListNode* next = cur->next;
			cur->next = revPrev;
			revPrev = cur;
			cur = next;
		}
		// ����curҪô��rear��ҪôΪ��
		// revPrev�Ƿ�תͷ
		ListNode* tail(nullptr);
		if (prev) {// prev�����ǿ�
			tail = prev->next;
			prev->next = revPrev;
			tail->next = cur; // �Ƿ�Ϊ�ղ�Ӱ��
			return head;
		}
		else {
			// ��תβ��head
			head->next = cur;
			return revPrev;
		}
	}
};



// ��������ɾȥ�ܺ�ֵΪ��������ڵ�
//https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

class Solution {
public:
	ListNode* removeZeroSumSublists(ListNode* head) {
		// ��ϣ����ǰ׺��
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
		while (cur) { // ���nextָ����ͬǰ׺�͵�next
			sum += cur->val;
			cur->next = sumToNode[sum]->next;
			cur = cur->next;
		}
		ListNode* ret = guard->next;
		delete guard;
		return ret;
	}
};