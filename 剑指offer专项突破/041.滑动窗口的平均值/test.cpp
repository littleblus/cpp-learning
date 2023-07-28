#include <queue>
using namespace std;

class MovingAverage {
	queue<int> _q;
	size_t _sz;
	double _sum;
public:
	/** Initialize your data structure here. */
	MovingAverage(int size) 
		:_q(queue<int>())
		,_sz(size)
		,_sum(0.0)
	{}

	double next(int val) {
		if (_q.size() != _sz) {
			_q.push(val);
			_sum += val;
			return _sum / _q.size();
		}
		else {
			_sum -= _q.front();
			_q.pop();
			_q.push(val);
			_sum += val;
			return _sum / _sz;
		}
	}
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */