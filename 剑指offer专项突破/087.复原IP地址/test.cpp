#include <vector>
#include <string>
using namespace std;

class Solution {
	void dfs(string& str, int i, int partCount) {
		if (i == str.size() && partCount == 4) {
			// 去除第一个 '.'
			ret.push_back(string(cur.begin() + 1, cur.end()));
		}
		else if (partCount < 4) {
			for (int j = i + 1; j - i <= 3 && j <= str.size(); j++) {
				// 前导0只能为0
				if (str[i] == '0') {
					cur += ".0";
					dfs(str, i + 1, partCount + 1);
					do {
						cur.pop_back();
					} while (cur.back() != '.');
					cur.pop_back();
					break;
				}
				else {
					string tmp(str.begin() + i, str.begin() + j);
					if (stoi(tmp) <= 255) {
						cur += '.' + tmp;
						dfs(str, j, partCount + 1);
						do {
							cur.pop_back();
						} while (cur.back() != '.');
						cur.pop_back();
					}
				}
			}
		}
	}

	string cur;
	vector<string> ret;
public:
	vector<string> restoreIpAddresses(string s) {
		dfs(s, 0, 0);
		return ret;
	}
};