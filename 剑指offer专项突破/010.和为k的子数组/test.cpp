#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> sum_count;//哈希表 加和-出现次数
		sum_count.insert({ 0,1 });//加和-k等于0
		int sum(0), count(0);
		for (auto e : nums) {
			sum += e;
			auto it = sum_count.find(sum - k);
			count += it == sum_count.end() ? 0 : it->second;
			it = sum_count.find(sum);
			if (it == sum_count.end()) {//不存在
				sum_count.insert({ sum, 1 });
			}
			else {
				it->second++;
			}
		}
		return count;
	}
};

int main() {
	Solution s;
	vector<int>t{1, 1, 1};
	s.subarraySum(t, 2);
	return 0;
}