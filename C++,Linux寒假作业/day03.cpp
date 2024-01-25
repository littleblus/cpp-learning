#include <string>
#include <algorithm>

using namespace std;

// 反转字符串中的单词 III
// https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
class Solution {
public:
    string reverseWords(string s) {
        auto begin = s.begin();
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (*it == ' ') {
                reverse(begin, it);
                begin = next(it);
            }
        }
        reverse(begin, s.end());
        return s;
    }
};



// 连续字符
// https://leetcode.cn/problems/consecutive-characters/description/
class Solution {
public:
    int maxPower(string s) {
        char cur = '\0';
        int cnt = 1, maxCnt = 0;
        for (auto ch : s) {
            if (ch != cur) {
                cur = ch;
                maxCnt = max(cnt, maxCnt);
                cnt = 1;
            }
            else {
                cnt++;
            }
        }
        maxCnt = max(cnt, maxCnt);
        return maxCnt;
    }
};