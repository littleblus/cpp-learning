#include <bits/stdc++.h>

using namespace std;

// 键盘行
// https://leetcode.cn/problems/keyboard-row/description/
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> chToNum;
        string l1 = "qwertyuiop";
        for (auto c : l1) {
            chToNum[c] = 1;
        }
        string l2 = "asdfghjkl";
        for (auto c : l2) {
            chToNum[c] = 2;
        }
        string l3 = "zxcvbnm";
        for (auto c : l3) {
            chToNum[c] = 3;
        }
        vector<string> ret;
        for (auto& str : words) {
            int n = chToNum[tolower(str[0])];
            bool add = true;
            for (auto c : str) {
                if (n != chToNum[tolower(c)]) {
                    add = false;
                    break;
                }
            }
            if (add) ret.emplace_back(str);
        }
        return ret;
    }
};



// 宝石与石头
// https://leetcode.cn/problems/jewels-and-stones/
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jew(jewels.begin(), jewels.end());
        int cnt = 0;
        for (auto c : stones) {
            if (jew.count(c)) cnt++;
        }
        return cnt;
    }
};