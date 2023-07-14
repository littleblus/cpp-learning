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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* guard = new ListNode(0, head);
        ListNode* front = head;
        ListNode* back = guard;

        while (front && n--) {
            front = front->next;
        }
        while (front) {
            front = front->next;
            back = back->next;
        }
        ListNode* del = back->next;
        back->next = back->next->next;
        ListNode* ans = guard->next;
        delete del;
        delete guard;
        return ans;
    }
};