#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 两种排序方法
bool isDict(vector<string>& vs) {
	for (size_t i = 1; i < vs.size(); i++) {
		string& s1(vs[i - 1]), & s2(vs[i]);
		size_t len = min(s1.size(), s2.size());
		if (s1.size() == s2.size()) {
			if (s1 == s2)
				return false;
		}
		else {
			for (size_t j = 0; j < len; j++) {
				if (s1[j] > s2[j])
					return false;
			}
		}
		
	}
	return true;
}

bool isLength(vector<string>& vs) {
	for (size_t i = 1; i < vs.size(); i++) {
		string& s1(vs[i - 1]), & s2(vs[i]);
		if (s1.size() >= s2.size())
			return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	vector<string> vs;
	while (n--) {
		string tmp;
		cin >> tmp;
		vs.emplace_back(tmp);
	}
	bool dict(isDict(vs)), length(isLength(vs));
	if (dict == false && length == false)
		cout << "none" << endl;
	else if (dict == true && length == false)
		cout << "lexicographically" << endl;
	else if (dict == false && length == true)
		cout << "lengths" << endl;
	else
		cout << "both" << endl;
	return 0;
}



// 输出两个数的最小公倍数
int main() {
	int a, b;
	cin >> a >> b;
	int big(a), little(b);
	do {
		int tmp = big % little;
		big = little;
		little = tmp;
	} while (little);
	cout << big * (a / big) * (b / big) << endl;
	return 0;
}