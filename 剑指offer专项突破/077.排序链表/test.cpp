#include <algorithm>
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
public:
	ListNode* sortList(ListNode* head) {
        vector<int> vlist;
        while (head) {
            vlist.push_back(head->val);
            head = head->next;
        }
        sort(vlist.begin(), vlist.end());
        ListNode* guard = new ListNode(-1);
        ListNode* cur = guard;
        for (auto e : vlist) {
            cur->next = new ListNode(e);
            cur = cur->next;
        }
        ListNode* ret = guard->next;
        delete guard;
        return ret;
	}
};