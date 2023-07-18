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
	void reorderList(ListNode* head) {
		// �ҵ�������м�ڵ㲢�ָ�
		// ��ת�󲿷�����
		// �ϲ�����ڵ�

		if (head->next == nullptr)
			return;
		ListNode* guard = new ListNode(-1, head);
		ListNode* slow(guard), * fast(head);
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		// ��ʱslow����һ���ڵ�����м�ڵ�
		ListNode* head2 = slow->next;
		slow->next = nullptr;
		// ��ת�󲿷�����
		ListNode* prev(nullptr), * cur2(head2);
		while (cur2) {
			ListNode* next = cur2->next;
			cur2->next = prev;
			prev = cur2;
			cur2 = next;
		}
		cur2 = head2 = prev;
		prev = guard;
		// �ϲ�����ڵ�
		ListNode* cur1 = head;
		while (cur1 && cur2) {
			ListNode* next1(cur1->next);
			ListNode* next2(cur2->next);
			cur1->next = cur2;
			cur2->next = next1;
			cur1 = next1;
			cur2 = next2;
			prev = prev->next->next;
		}
		if (cur2) {
			prev->next = cur2;
		}
		delete guard;
	}
};