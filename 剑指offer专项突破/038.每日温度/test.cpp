#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		stack<size_t> pos;
		vector<int> ret;
		ret.resize(temperatures.size(), 0);
		// 待查找升温的温度
		int tmp;
		for (int i = 0; i < temperatures.size(); i++) {
			int tem = temperatures[i];
			if (pos.empty()) {
				tmp = tem;
				pos.push(i);
			}
			else {
				if (tem > tmp) {
					while (tem > tmp) {
						// 温度升高
						int tpos = pos.top();
						ret[tpos] = i - tpos;
						pos.pop();
						if (!pos.empty())
							tmp = temperatures[pos.top()];
						else
							break;
					}
				}
				tmp = tem;
				pos.push(i);
			}
		}
		return ret;
	}
};

int main() {
	Solution s;
	vector<int> v{55, 38, 53, 81, 61, 93, 97, 32, 43, 78};
	s.dailyTemperatures(v);
	return 0;
}