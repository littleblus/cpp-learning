#include <vector>
#include <iostream>
using namespace std;

class Solution {
	int check(vector<int>& piles, int speed) {
		int time = 0;
		for (int e : piles) {
			time += (e + speed - 1) / speed;
		}
		return time;
	}
public:
	int minEatingSpeed(vector<int>& piles, int h) {
		int max = 0;
		for (int e : piles)
			max = e > max ? e : max;
		int left(1), right(max);
		while (left < right) {
			int mid = left + right >> 1;
			if (check(piles, mid) > h)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
};