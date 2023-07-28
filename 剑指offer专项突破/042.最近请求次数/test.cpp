#include <queue>
using namespace std;

class RecentCounter {
	queue<int> _q;
	int timeRange = 3000;
public:
	RecentCounter() {}

	int ping(int t) {
		int left = t - 3000;
		while (!_q.empty() && _q.front() < left) {
			_q.pop();
		}
		_q.push(t);
		return _q.size();
	}
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */