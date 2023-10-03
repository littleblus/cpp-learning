#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		// lambda表达式
		auto sumGreater = [&](const pair<int, int>& p1, const pair<int, int>& p2)->bool {
			return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
			};
		// 待添加的数对，其中比较部分模板使用lambda表达式的类型推导传递
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(sumGreater)> que(sumGreater);
		// 先添加(i,0)的数对
		const int steps = min((int)nums1.size(), k);
		for (int i = 0; i < steps; i++) {
			que.emplace(i, 0);
		}
		// 求解
		vector<vector<int>> ret;
		while (k-- && !que.empty()) {
			// 结构化绑定
			auto [x, y] = que.top();
			que.pop();
			// 显式调用initializer_list
			ret.emplace_back(initializer_list<int>{ nums1[x], nums2[y] });
			if (y < nums2.size() - 1)
				que.emplace(x, y + 1);
		}
		return ret;
	}
};

void test() {
	priority_queue<int, vector<int>, greater<int>> que;
	que.emplace(1);
	que.emplace(2);
	que.emplace(3);
	que.emplace(4);
	que.emplace(5);
	que.emplace(6);
	que.emplace(7);
	cout << que.top() << endl;
}

int main() {
	/*Solution sol;
	vector<int> v1{ 1,7,11 }, v2{ 2,4,6 };
	sol.kSmallestPairs(v1, v2, 3);*/

	test();

	return 0;
}
