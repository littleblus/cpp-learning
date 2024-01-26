#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 字符串压缩
// https://leetcode.cn/problems/compress-string-lcci/description/
class Solution {
public:
    string compressString(string S) {
        if (S.size() == 0) return S;
        string ret;
        int cnt = 0;
        char cur = S[0];
        for (auto ch : S) {
            if (ret.size() >= S.size()) return S;
            if (ch == cur) cnt++;
            else {
                ret += cur;
                ret += to_string(cnt);
                cnt = 1;
                cur = ch;
            }
        }
        ret += cur;
        ret += to_string(cnt);
        return ret.size() >= S.size() ? S : ret;
    }
};



// 字符串相乘
// https://leetcode.cn/problems/multiply-strings/description/
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() > num2.size())
            return multiply(num2, num1);
        if (num1 == "0" || num2 == "0")
            return "0";
        reverse(num1.begin(), num1.end()), reverse(num2.begin(), num2.end());
        vector<int> ans(num1.size() + num2.size(), 0);
        for (int i = 0; i < num1.size(); i++) {
            for (int j = 0; j < num2.size(); j++) {
                ans[i + j] += (num1[i] - '0') * (num2[j] - '0');
                int cur(i + j), t(0);
                do {
                    ans[cur] += t;
                    t = ans[cur] / 10;
                    ans[cur] %= 10;
                    cur++;
                } while (t);
            }
        }
        string ret;
        for (auto e : ans)
            ret.push_back(e + '0');
        while (ret.size() > 1 && ret.back() == '0')
            ret.pop_back();
        reverse(ret.begin(), ret.end());
        return ret;
    }
};