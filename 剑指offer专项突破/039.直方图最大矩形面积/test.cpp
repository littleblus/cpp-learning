#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
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
};