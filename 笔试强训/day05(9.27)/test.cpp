#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPal(string s) {
	int front(0), back(s.size() - 1);
	while (front < back) {
		if (s[front] != s[back])
			return false;
		front++, back--;
	}
	return true;
}

int main() {
	string a, b;
	cin >> a >> b;
	string merge;
	int count = 0;
	for (size_t i = 0; i <= a.size(); i++) {
		merge = string(a.begin(), a.begin() + i) + b + string(a.begin() + i, a.end());
		if (isPal(merge))
			count++;
	}
	cout << count << endl;
	return 0;
}

// 通过90%用例（WA）
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (size_t i = 0; i < n; i++) {
        cin >> v[i];
    }
    // 求前缀和
    vector<int> frontSum(n);
    int sum = 0;
    for (size_t i = 0; i < n; i++) {
        sum += v[i];
        frontSum[i] = sum;
    }
    auto maxit = max_element(frontSum.begin(), frontSum.end());
    auto minit = min_element(frontSum.begin(), frontSum.end());
    if (maxit >= minit && *minit < 0)
        cout << *maxit - *minit << endl;
    else
        cout << *maxit << endl;
    return 0;
}