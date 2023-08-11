#include <vector>
using namespace std;

class Solution {
	bool check(int mid, vector<int>& arr) {
		return arr[mid] < arr[mid + 1];
	}
public:
	int peakIndexInMountainArray(vector<int>& arr) {
		int left(0), right(arr.size() - 1);
		while (left < right) {
			int mid = left + right >> 1;
			if (check(mid, arr)) // Âú×ãĞÔÖÊ£¬mid < mid + 1 
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
};