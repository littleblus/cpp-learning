class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;
};

class Solution {
	Node* flattenCore(Node* head) {
		if (!head)
			return nullptr;
		Node* tail(nullptr), * cur(head);
		while (cur) {
			Node* next = cur->next;
			if (cur->child) {
				Node* childHead = cur->child;
				Node* childTail = flattenCore(childHead);
				cur->child = nullptr;
				cur->next = childHead;
				childHead->prev = cur;
				childTail->next = next;
				if(next)
					next->prev = childTail;
				tail = childTail;
			}
			else {
				tail = cur;
			}
			cur = next;
		}
		return tail;
	}
public:
	Node* flatten(Node* head) {
		flattenCore(head);
		return head;
	}
};