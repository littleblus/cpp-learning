#include <iostream>
using namespace std;

class Node {
public:
	int val;
	Node* next;

	Node() {}

	Node(int _val) {
		val = _val;
		next = NULL;
	}

	Node(int _val, Node* _next) {
		val = _val;
		next = _next;
	}
};


class Solution {
public:
	Node* insert(Node* head, int insertVal) {
		if (!head) {
			head = new Node(insertVal);
			head->next = head;
		}
		else if (head->next == head) {
			// 链表中只有一个节点
			head->next = new Node(insertVal, head);
		}
		else {
			Node* prev(head), * cur(head->next);
			Node* maxNode(nullptr), * minNode(nullptr);
			int maxDiff = -1;
			bool ins = false;
			do {
				int vp(prev->val), vc(cur->val);
				if (vp - vc > maxDiff) {
					maxDiff = vp - vc;
					maxNode = prev;
					minNode = cur;
				}
				if (vp <= insertVal && insertVal <= vc) {
					ins = true;
					prev->next = new Node(insertVal, cur);
					break;
				}
				prev = prev->next, cur = cur->next;
			} while (prev != head);
			if (ins == false) {
				maxNode->next = new Node(insertVal, minNode);
			}
		}
		return head;
	}
};

int main() {
	Node n1(3), n2(4), n3(1);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n1;
	Solution s;
	s.insert(&n1, 2);
	return 0;
}