#include <string>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		int i = a.size() - 1, j = b.size() - 1, sum = 0, carry = 0;
		string ret;
		while (i >= 0 || j >= 0) {
			sum = 0;
			sum += i >= 0 ? a[i] - '0' : 0;
			sum += j >= 0 ? b[j] - '0' : 0;
			i--, j--;
			sum += carry;
			carry = sum > 1 ? 1 : 0;
			sum = sum > 1 ? sum - 2 : sum;
			ret += sum + '0';
		}
		if (carry) {
			ret += '1';
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

int main() {
	Solution s;
	s.addBinary("11", "10");
}