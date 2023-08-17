#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		// ¼ÆÊýÅÅÐò
		int arr[1001]{};
		vector<int> ret;
		for (int e : arr1) {
			arr[e]++;
		}
		for (int e : arr2) {
			while (arr[e]--) {
				ret.push_back(e);
			}
		}
		for (int i = 0; i <= 1000; i++) {
			if (arr[i] > 0) {
				while (arr[i]--) {
					ret.push_back(i);
				}
			}
		}
		return ret;
	}
};

int main() {
	Solution s;
	vector<int> v1{ 2,3,1,3,2,4,6,7,9,2,19 }, v2{ 2,1,4,3,9,6 };
	s.relativeSortArray(v1, v2);
	return 0;
}