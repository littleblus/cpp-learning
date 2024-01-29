#include <string>
#include <vector>

using namespace std;

// 将一维数组转变成二维数组
// https://leetcode.cn/problems/convert-1d-array-into-2d-array/description/
class Solution {
public:
	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
		vector<vector<int>> ret;
		if (m * n != original.size()) return ret;
		ret.emplace_back();
		int i = 0;
		for (auto e : original) {
			if (i != n) {
				ret.back().push_back(e);
				i++;
			}
			else {
				i = 1;
				ret.emplace_back();
				ret.back().push_back(e);
			}
		}
		return ret;
	}
};



// 用栈操作构建数组
// https://leetcode.cn/problems/build-an-array-with-stack-operations/description/
class Solution {
public:
	vector<string> buildArray(vector<int>& target, int n) {
		vector<string> ret;
		int j = 0;
		for (int i = 1; i <= n; i++) {
			if (j == target.size()) break;
			if (target[j] == i) {
				ret.emplace_back("Push");
				j++;
			}
			else {
				ret.emplace_back("Push");
				ret.emplace_back("Pop");
			}
		}
		return ret;
	}
};