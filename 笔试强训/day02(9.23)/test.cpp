#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n <= 2)
		return 1;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	bool isUp(false), isDown(false);
	int ret = 1;
	for (int i = 2; i < n; i++) {
		if (v[i] == v[i - 1])
			continue;
		if (isUp == false && isDown == false) {
			if (v[i - 1] < v[i])
				isUp = true;
			else
				isDown = true;
		}
		else {
			if (isUp && v[i - 1] > v[i]) {
				ret++;
				isUp = isDown = false;
			}
			else if (isDown && v[i - 1] < v[i]) {
				ret++;
				isUp = isDown = false;
			}
		}
	}
	cout << ret << endl;
	return 0;
}

int main() {
	string s;
	getline(cin, s);
	vector<string> vs;
	for (auto ch : s) {
		if (ch == ' ')
			vs.push_back("");
		else {
			vs.back().push_back(ch);
		}
	}
	for (auto it = vs.rbegin(); it != vs.rend() - 1; ++it) {
		cout << *it << ' ';
	}
	cout << vs[0] << endl;
	return 0;
}