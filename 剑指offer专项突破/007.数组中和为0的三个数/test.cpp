#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>>ret;
		if (nums.size() < 3)
			return ret;
		sort(nums.begin(), nums.end());
		int temp, i = 0;
		while (i < nums.size() - 2) {
			twoSum(nums, -nums[i], i, ret);
			temp = nums[i];
			while (i < nums.size() && nums[i] == temp)//�ų��ظ��Ĳ���
				i++;
		}
		return ret;
	}
private:
	void twoSum(vector<int>& numbers, int target, int k, vector<vector<int>>& ret) {
		int i = k + 1, j = numbers.size() - 1;//�ڵ�ǰ����֮���ң������ظ�
		while (i < j) {
			int sum = numbers[i] + numbers[j];
			if (sum > target) {
				j--;
			}
			else if (sum < target) {
				i++;
			}
			else {
				ret.push_back(vector<int>{numbers[k], numbers[i], numbers[j]});
				int temp = numbers[i];
				while (i < j && numbers[i] == temp)//���������ظ�
					i++;
			}
		}
	}
};

int main() {
	Solution s;
	vector<int>test{-1, 0, 1, 0};
	s.threeSum(test);
}