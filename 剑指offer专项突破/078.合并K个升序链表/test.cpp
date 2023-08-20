#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		ListNode* cur1(l1), * cur2(l2), * guard(new ListNode(-1)), * curNew(guard);
		while (cur1 && cur2) {
			if (cur1->val <= cur2->val) {
				curNew->next = cur1;
				cur1 = cur1->next;
			}
			else {
				curNew->next = cur2;
				cur2 = cur2->next;
			}
			curNew = curNew->next;
		}
		while (cur1) {
			curNew->next = cur1;
			cur1 = cur1->next;
			curNew = curNew->next;
		}
		while (cur2) {
			curNew->next = cur2;
			cur2 = cur2->next;
			curNew = curNew->next;
		}
		ListNode* ret = guard->next;
		delete guard;
		return ret;
	}
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
			return nullptr;
		vector<ListNode*> tmp;
		while (lists.size() != 1) {
			int i;
			for (i = 0; i < lists.size() - 1; i += 2) {
				tmp.push_back(merge2Lists(lists[i], lists[i + 1]));
			}
			if (i == lists.size() - 1)
				tmp.push_back(lists[i]);
			swap(tmp, lists);
			tmp.clear();
		}
		return lists[0];
	}
};