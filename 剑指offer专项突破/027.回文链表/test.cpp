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
	bool isPalindrome(ListNode* head) {
		// ·Ö¸î£¬·´×ª

		ListNode* guard(new ListNode(-1, head)), * slow(guard), * fast(head);
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow->next;
		slow->next = nullptr;
		ListNode* prev(nullptr), * cur(fast);
		while (cur) {
			ListNode* next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		fast = prev;
		delete guard;
		while (head && fast) {
			if (head->val != fast->val)
				return false;
			head = head->next;
			fast = fast->next;
		}
		return true;
	}
};