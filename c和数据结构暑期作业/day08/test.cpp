#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 数列
//https://www.nowcoder.com/practice/1843c3b052984e3f98c68935ea3c0d79?tpId=182&&tqId=34866&rp=1&ru=/ta/exam-all&qru=/ta/exam-all/question-ranking
int main() {
	int n;
	cin >> n;
	// a1 = 1, a2 = 2, ... , an = 2 * an − 1 + an - 2 (n > 2)
	vector<int> v{1, 2};
	v.reserve(1e6);
	int prev(1), back(2);
	int k = 1e6;
	while (k--) {
		int next = 2 * back + prev;
		prev = back;
		back = next % 32767;
		v.push_back(back);
	}

	while (n--) {
		int k;
		cin >> k;
		cout << v[k - 1] << endl;
	}
	return 0;
}



// 统计字符
//https://www.nowcoder.com/practice/539054b4c33b4776bc350155f7abd8f5?tpId=37&&tqId=21263&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking
int main() {
	// 输入一行字符，分别统计出包含英文字母、空格、数字和其它字符的个数
	string str;
	getline(cin, str);
	int r1(0), r2(0), r3(0), r4(0);
	for (auto e : str) {
		if ((e >= 'a' && e <= 'z') || (e >= 'A' && e <= 'Z'))
			r1++;
		else if (e == ' ')
			r2++;
		else if (e >= '0' && e <= '9')
			r3++;
		else
			r4++;
	}
	cout << r1 << endl << r2 << endl << r3 << endl << r4 << endl;
	return 0;
}