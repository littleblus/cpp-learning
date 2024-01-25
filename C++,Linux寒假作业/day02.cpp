#include<unordered_map>

using namespace std;

// 检查两个字符串是否几乎相等
// https://leetcode.cn/problems/check-whether-two-strings-are-almost-equivalent/description/
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char, int> map;
        for (int i = 0; i < word1.size(); i++) {
            map[word1[i]]++;
        }
        for (int i = 0; i < word2.size(); i++) {
            if (--map[word2[i]] < -3) {
                return false;
            }
        }
        for (auto& [_, value] : map) {
            if (value > 3) {
                return false;
            }
        }
        return true;
    }
};



// 字符串解码
// https://leetcode.cn/problems/decode-string/description/
class Solution {
public:
    string decodeString(string s) {
        string ret, tmp;
        int times(0), count(0);
        bool have = false;
        while (true) {
            for (auto ch : s) {
                if (isdigit(ch)) {
                    if (count == 0) {
                        times = times * 10 + ch - '0';
                    }
                    else {
                        tmp += ch;
                    }
                }
                else if (ch == '[') {
                    have = true;
                    if (count) {
                        tmp += ch;
                    }
                    count++;
                }
                else if (ch == ']') {
                    count--;
                    if (count == 0) {
                        while (times--) {
                            ret += tmp;
                        }
                        times = 0;
                        tmp.clear();
                    }
                    else {
                        tmp += ch;
                    }
                }
                else {
                    if (count) {
                        tmp += ch;
                    }
                    else {
                        ret += ch;
                    }
                }
            }
            if (!have) break;
            s = ret;
            ret.clear();
            times = 0;
            have = false;
        }
        return ret;
    }
};