#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> map;
		priority_queue<pair<int, int>> heap;
		for (auto e : nums) {
			map[e]++;
		}
		for (auto& e : map) {
			heap.push({ e.second,e.first });
		}
		vector<int> ret;
		while (k--) {
			ret.push_back(heap.top().second);
			heap.pop();
		}
		return ret;
	}
};