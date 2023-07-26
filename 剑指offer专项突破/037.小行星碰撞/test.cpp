#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		stack<int> buf;
		for (auto e : asteroids) {
			if (buf.empty())
				buf.push(e);
			else {
				if (buf.top() > 0 && e < 0) {
					int left(buf.top());
					if (left < -e) {
						while (left < -e) {
							if (left < 0) {
								buf.push(e);
								break;
							}
							buf.pop();
							if (!buf.empty())
								left = buf.top();
							else {
								buf.push(e);
								break;
							}
						}
						// left >= right
						if (left + e == 0)
							buf.pop();
					}
					else if (left + e == 0) {
						buf.pop();
					}
				}
				else // ²»Ïà×²
					buf.push(e);
			}
		}
		vector<int> res;
		while (!buf.empty()) {
			res.push_back(buf.top());
			buf.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

int main() {
	Solution s;
	vector<int> v{-2, -2, 1, -2};
	s.asteroidCollision(v);
	return 0;
}