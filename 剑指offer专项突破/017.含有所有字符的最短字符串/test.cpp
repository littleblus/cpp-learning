#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	string minWindow(string s, string t) {
		string ret;
		if (s.size() < t.size())
			return ret;
		//���Ҿ�Ϊ������
		int hash[128]{ 0 }, cmp[128]{ 0 }, left(0), right(t.size() - 1), minlen(s.size());
		for (char e : t) {
			cmp[e]++;
		}
		for (int i = left; i <= right; i++) {
			hash[s[i]]++;
		}
		while (true) {
			if (allChar(hash, cmp)) {//���������ַ�
				if (right - left + 1 <= minlen) {
					minlen = right - left + 1;
					ret = s.substr(left, minlen);
				}
				hash[s[left]]--;
				left++;
			}
			else {//����
				right++;
				if (right == s.size())
					break;
				hash[s[right]]++;
			}
		}
		return ret;
	}
private:
	bool allChar(int* hash, int* cmp) {//��������ù�ϣ����ϣ����������
		for (int i = 0; i < 128; i++) {
			if (cmp[i] != 0 && hash[i] - cmp[i] < 0) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	string s("a"), t("a");
	Solution s1;
	s1.minWindow(s, t);
	return 0;
}