#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		if (timePoints.size() > 24 * 60)
			return 0;
		int time[1440]{ 0 };
		for (auto& e : timePoints) {
			int pos = ((e[0] - '0') * 10 + (e[1] - '0')) * 60 + ((e[3] - '0') * 10 + (e[4] - '0'));
			time[pos]++;
		}
		int res(1440), left(0), right(1);
		while (right < 1440) {
			while (right < 1440 && !time[right]) {
				right++;
			}
			if (right == 1440)
				goto next;
			if (time[left]) {
				if (time[left] > 1)
					return 0;
				res = right - left < res ? right - left : res;
			}
			left = right;
			right++;
		}
	next:
		// 处理第一个
		right = 0;
		while (!time[right]) {
			right++;
		}
		res = right + 1440 - left < res ? right + 1440 - left : res;
		return res;
	}
};

int main() {
	Solution s;
	vector<string> v{"05:37", "21:09", "00:00"};
	s.findMinDifference(v);
	return 0;
}