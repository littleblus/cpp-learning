#include <vector>
using namespace std;

class Solution {
public:
	int minCost(vector<vector<int>>& costs) {
		// r(i) = min{g(i-1), b(i-1)} + costs[i]
		// ...
		int red(costs[0][0]), green(costs[0][1]), blue(costs[0][2]);
		for (int i = 1; i < costs.size(); i++) {
			int tmpR(red), tmpG(green), tmpB(blue);
			red = min(tmpG, tmpB) + costs[i][0];
			green = min(tmpR, tmpB) + costs[i][1];
			blue = min(tmpR, tmpG) + costs[i][2];
		}
		return min(red, min(green, blue));
	}
};