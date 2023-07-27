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
				// ��ջ
				int h = heights[pos.top()];
				pos.pop();
				// �����Ϊh�����������
				int l = i - pos.top() - 1;
				maxS = max(h * l, maxS);
			}
			pos.push(i);
		}
		// �����Ҳ��޸������ӵ����
		while (pos.top() != -1) {
			// ��ջ
			int h = heights[pos.top()];
			pos.pop();
			// �����Ϊh�����������
			int l = heights.size() - pos.top() - 1;
			maxS = max(h * l, maxS);
		}
		return maxS;
	}
};