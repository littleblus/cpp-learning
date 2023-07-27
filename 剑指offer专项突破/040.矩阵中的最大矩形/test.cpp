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