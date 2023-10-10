#include <vector>

using namespace std;

class Solution {
    int findFather(vector<int>& fathers, size_t cur) {
        if (fathers[cur] != cur)
            fathers[cur] = findFather(fathers, fathers[cur]);
        return fathers[cur];
    }

    bool isUnion(vector<int>& fathers, size_t i, size_t j) {
        int fi(findFather(fathers, i)), fj(findFather(fathers, j));
        if (fi != fj) {
            fathers[fi] = fj;
            return true;
        }
        return false;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> fathers(isConnected.size());
        for (size_t i = 0; i < fathers.size(); i++) {
            fathers[i] = i;
        }
        int count = isConnected.size();
        for (size_t i = 0; i < isConnected.size(); i++) {
            for (size_t j = 0; j < isConnected.size(); j++) {
                if (isConnected[i][j] == 1 && isUnion(fathers, i, j))
                    count--;
            }
        }
        return count;
    }
};