#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
	int largestRectangleArea(vector<int>& heights) {
		stack<int> pos;
		pos.push(-1);
		int maxS = 0;
		for (int i = 0; i < heights.size(); i++) {
			while (pos.top() != -1 && heights[i] < heights[pos.top()]) {
				// 出栈
				int h = heights[pos.top()];
				pos.pop();
				// 计算高为h的面积最大矩形
				int l = i - pos.top() - 1;
				maxS = max(h * l, maxS);
			}
			pos.push(i);
		}
		// 处理右侧无更矮柱子的情况
		while (pos.top() != -1) {
			// 出栈
			int h = heights[pos.top()];
			pos.pop();
			// 计算高为h的面积最大矩形
			int l = heights.size() - pos.top() - 1;
			maxS = max(h * l, maxS);
		}
		return maxS;
	}
public:
	int maximalRectangle(vector<string>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return 0;
		int res = 0;
		vector<int> heights(matrix[0].size(), 0);
		for (auto& e : matrix) {
			for (int i = 0; i < e.size(); i++) {
				if (e[i] == '0')
					heights[i] = 0;
				else
					heights[i]++;
			}
			res = max(res, largestRectangleArea(heights));
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<string> v{ "10100", "10111", "11111", "10010" };
	s.maximalRectangle(v);
	return 0;
}