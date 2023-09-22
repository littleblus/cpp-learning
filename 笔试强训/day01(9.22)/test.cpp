#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	int range = N * 3;
	vector<int> input(range);
	for (size_t i = 0; i < range; i++) {
		cin >> input[i];
	}
	sort(input.begin(), input.end(), greater<>());
	size_t ret = 0;
	int pos = 1;
	for (int i = 0; i < N; i++) {
		ret += input[pos];
		pos += 2;
	}
	cout << ret << endl;
	return 0;
}

//int main() {
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	vector<char> dict(256, true);
//	for (auto ch : s2) {
//		dict[ch] = false;
//	}
//	string res;
//	for (auto ch : s1) {
//		if (dict[ch])
//			res.push_back(ch);
//	}
//	cout << res << endl;
//
//	return 0;
//}