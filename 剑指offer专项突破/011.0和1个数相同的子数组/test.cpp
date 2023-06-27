#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		unordered_map<int, int>sumToIndex;
		//将所有0改为-1
		for (auto& e : nums) {
			if (e == 0)
				e = -1;
		}
		int sum(0), res(0);
		sumToIndex[0] = -1;//特例补充
		for (int i = 0; i < nums.size(); i++) {
			//若前i个数字的和是k，前j个（j>i）的数字和也是k，那么(i,k]的数字之和为0
			sum += nums[i];
			auto it = sumToIndex.find(sum);
			if (it != sumToIndex.end())//找到了
				res = max(res, i - it->second);
			else
				sumToIndex.insert({ sum,i });
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int>t{0,1};
	s.findMaxLength(t);
	return 0;
}