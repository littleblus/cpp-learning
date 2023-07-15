#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        // 哈希表解法
        ListNode *cur(head), *ret(nullptr);
        unordered_map<ListNode*, int> siteToPos;
        int i = 1;
        while (cur) {
            auto it = siteToPos.find(cur);
            if (it == siteToPos.end()) {
                // 没找到
                siteToPos.insert({ cur, i++ });
            }
            else {
                return it->first;
            }
            cur = cur->next;
        }
        return nullptr;
    }
};