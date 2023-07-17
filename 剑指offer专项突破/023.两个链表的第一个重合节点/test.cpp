#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		int lenA(0), lenB(0);
		ListNode *curA(headA), *curB(headB);
		while (curA != nullptr) {
			lenA++;
			curA = curA->next;
		}
		while (curB != nullptr) {
			lenB++;
			curB = curB->next;
		}
		int diff = abs(lenA - lenB);
		curA = headA,curB = headB;
		if (lenA > lenB) {// A先走
			while (diff--) {
				curA = curA->next;
			}
		}
		else {
			while (diff--) {
				curB = curB->next;
			}
		}
		while (curA) {// 随便哪个都行
			if (curA == curB)
				return curA;
			curA = curA->next;
			curB = curB->next;
		}
		return nullptr;
	}
};