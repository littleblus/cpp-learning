#include <vector>
using namespace std;

class Solution {
    void dfs(int n, int i, int k) {
        if (cur.size() == k) {
            ret.push_back(cur);
            return;
        }
        if (i > n)
            return;
        dfs(n, i + 1, k);

        cur.push_back(i);
        dfs(n, i + 1, k);
        cur.pop_back();
    }

    vector<vector<int>> ret;
    vector<int> cur;
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, 1, k);
        return ret;
    }
};