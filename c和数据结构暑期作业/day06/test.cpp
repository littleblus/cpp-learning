#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// µÝ¹é³Ë·¨
//https://leetcode.cn/problems/recursive-mulitply-lcci/
//class Solution {
//private:
//	int mulCore(int num, int count, int res) {
//		if (count == 0)
//			return num;
//		
//		res += mulCore(num, count - 1, res);
//		return res;
//	}
//public:
//	int multiply(int A, int B) {
//		return mulCore(A, B, A) - A;
//	}
//};



// Ìô7
//https://www.nowcoder.com/practice/ba241b85371c409ea01ac0aa1a8d957b?tpId=37&&tqId=21278&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking
int main() {
	int n;
	cin >> n;
	unordered_set<int> set;
	for (int i = 7; i <= n; i += 7)
		set.insert(i);
	// °üº¬7µÄ
	for (int i = 1; i <= n; i++) {
		string s = to_string(i);
		size_t pos = s.find('7');
		if (pos != string::npos)
			set.insert(i);
	}
	cout << set.size() << endl;

	return 0;
}