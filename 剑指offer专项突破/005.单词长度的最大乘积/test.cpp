#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	int maxProduct(vector<string>& words) {
		int* flags = new int[words.size()]();
		for (int i = 0; i < words.size(); i++) {
			for (auto e : words[i]) {
				flags[i] |= 1 << (e - 'a');
			}
		}
		int ret = 0;
		for (int i = 0; i < words.size(); i++) {
			for (int j = i + 1; j < words.size(); j++) {
				if ((flags[i] & flags[j]) == 0) {
					int len = words[i].size() * words[j].size();
					ret = len > ret ? len : ret;
				}
			}
		}
		delete[] flags;
		return ret;
	}
};

int main() {
	Solution s;
	vector<string>test{ "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
	s.maxProduct(test);
}