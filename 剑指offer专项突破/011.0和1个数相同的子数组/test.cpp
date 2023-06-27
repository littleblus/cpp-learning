#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		unordered_map<int, int>sumToIndex;
		//������0��Ϊ-1
		for (auto& e : nums) {
			if (e == 0)
				e = -1;
		}
		int sum(0), res(0);
		sumToIndex[0] = -1;//��������
		for (int i = 0; i < nums.size(); i++) {
			//��ǰi�����ֵĺ���k��ǰj����j>i�������ֺ�Ҳ��k����ô(i,k]������֮��Ϊ0
			sum += nums[i];
			auto it = sumToIndex.find(sum);
			if (it != sumToIndex.end())//�ҵ���
				res = max(res, i - it->second);
			else
				sumToIndex.insert({ sum,i });
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int>t{0,1};
	s.findMaxLength(t);
	return 0;
}