#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        int end(1), count(0), add(0), maxValue(INT_MIN);
        queue<TreeNode*> q;
        vector<int> ret;
        if (!root)
            return ret;
        q.push(root);
        while (!q.empty()) {
            if (q.front()->val > maxValue)
                maxValue = q.front()->val;
            if (q.front()->left) {
                q.push(q.front()->left);
                add++;
            }
            if (q.front()->right) {
                q.push(q.front()->right);
                add++;
            }
            q.pop();
            count++;
            if (count == end) {
                end += add;
                ret.push_back(maxValue);
                add = 0;
                maxValue = INT_MIN;
            }
        }
        return ret;
    }
};