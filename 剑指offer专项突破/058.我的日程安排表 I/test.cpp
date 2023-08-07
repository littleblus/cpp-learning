#include <map>
using namespace std;

class MyCalendar {
	map<int, int> _cal;
public:
	MyCalendar() {}

	bool book(int start, int end) {
		auto it = _cal.lower_bound(start);
		if (it != _cal.end() && it->first < end)
			return false;
		if (it != _cal.begin() && (--it)->second > start)
			return false;
		_cal[start] = end;
		return true;
	}
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */