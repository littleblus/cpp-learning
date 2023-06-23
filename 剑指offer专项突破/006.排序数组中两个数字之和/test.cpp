#include <vector>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int i = 0, j = numbers.size() - 1;
		while (i < j) {
			int sum = numbers[i] + numbers[j];
			if (sum > target)
				j--;
			else if (sum < target)
				i++;
			else
				break;
		}
		return vector<int>{i, j};
	}
};

int main() {
	Solution s;
	vector<int>test{1, 2, 4, 6, 10};
	s.twoSum(test, 8);
}