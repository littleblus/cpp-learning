#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		set<long long> s;
		for (size_t i = 0; i < nums.size(); i++) {
			auto lower = s.lower_bound((long long)nums[i] - t);
			if (lower != s.end() && *lower <= (long long)nums[i] + t)
				return true;
			else
				s.insert(nums[i]);
			if (i >= k) // 每次只找后面就行，不需要找前面
				s.erase(nums[i - k]);
		}
		return false;
	}
};