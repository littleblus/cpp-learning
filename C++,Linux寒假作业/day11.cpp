#include <unordered_map>

using namespace std;

// 找不同
// https://leetcode.cn/problems/find-the-difference/description/
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> dict;
        for (auto ch : s) {
            ++dict[ch];
        }
        for (auto ch : t) {
            if (--dict[ch] < 0) return ch;
        }
        return 0;
    }
};



// 长度为三且各字符不同的子字符串
// https://leetcode.cn/problems/substrings-of-size-three-with-distinct-characters/
class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.size() < 3) return 0;
        int dict[26]{};
        int i(0), j(3), cnt(0);
        for (int x = i; x < j; x++) dict[s[x] - 'a']++;
        while (j <= s.size()) {
            bool add = true;
            for (int x = i; x < j; x++) {
                if (dict[s[x] - 'a'] != 1) add = false;
            }
            if (add) cnt++;
            if (j < s.size()) {
                dict[s[i] - 'a']--, dict[s[j] - 'a']++;
            }
            i++, j++;
        }
        return cnt;
    }
};