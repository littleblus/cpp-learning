#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> ret;
		if (s.size() < p.size())
			return ret;
		int hash[26]{ 0 };
		for (char e : p) {
			hash[e - 'a']++;
		}
		for (int i = 0; i < p.size(); i++) {
			hash[s[i] - 'a']--;
		}
		//均为闭区间
		int left(0), right((int)p.size() - 1);
		while (true) {
			if (isZero(hash, 26))
				ret.push_back(left);
			hash[s[left] - 'a']++;
			left++;
			right++;
			if (right == s.size())
				break;
			hash[s[right] - 'a']--;
		}
		return ret;
	}
private:
	bool isZero(int* arr, size_t num) {
		for (int i = 0; i < num; i++) {
			if (arr[i] != 0)
				return false;
		}
		return true;
	}
};

int main() {
	string s("cbaebabacd"), p("abc");
	Solution t;
	t.findAnagrams(s, p);
	return 0;
}