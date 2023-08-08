#include <queue>
#include <iostream>
using namespace std;

class KthLargest {
	priority_queue<int,vector<int>,greater<int>> _que;
	int _k;
public:
	KthLargest(int k, vector<int>& nums) {
		_k = k;
		if (k <= nums.size()) {
			_que = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.begin() + k);
			auto it = nums.begin() + k;
			while (it != nums.end()) {
				if (*it > _que.top()) {
					_que.pop();
					_que.push(*it);
				}
				++it;
			}
		}
		else {
			_que = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
		}
	}

	int add(int val) {
		if (_k > _que.size()) {
			_que.push(val);
		}
		else if(val > _que.top()) {
			_que.pop();
			_que.push(val);
		}
		return _que.top();
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {
	int arr[]{ 1,2,3,4,5,6,7 };
	priority_queue<int, vector<int>, greater<int>> test(arr, arr + 7);
	cout << test.top();
}