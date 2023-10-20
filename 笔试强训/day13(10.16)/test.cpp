#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 参数解析
int main() {
	string cmd;
	getline(cin, cmd);
	string tmp;
	vector<string> vs;
	char ch;
	int pos(0), cnt(0);
	bool quo = false;
	while ((ch = cmd[pos++]) != '\0') {
		if (quo) {
			if (ch == '"') {
				quo = false;
			}
			else {
				tmp.push_back(ch);
			}
		}
		else {
			if (ch == '"') {
				quo = true;
			}
			else if (ch == ' ') {
				vs.emplace_back(tmp);
				tmp.clear();
				cnt++;
			}
			else {
				tmp.push_back(ch);
			}
		}
	}
	if (!tmp.empty()) {
		vs.emplace_back(tmp);
		tmp.clear();
		cnt++;
	}
	cout << cnt << endl;
	for (auto& str : vs) {
		cout << str << endl;
	}
	return 0;
}



// 跳石板
void get_y(vector<int>& ys, int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ys.emplace_back(i);
			// 添加对应的约数
			if (n / i != i) {
				ys.emplace_back(n / i);
			}
		}
	}
}

int jump(int n, int m) {
	vector<int> step(m + 1, INT_MAX);
	step[n] = 0;
	for (int i = n; i < m; i++) {
		if (step[i] == INT_MAX)
			continue;
		vector<int> ys;
		get_y(ys, i);
		for (int y : ys) {
			if (i + y <= m && step[i + y] != INT_MAX) {
				step[i + y] = min(step[i] + 1, step[i + y]);
			}
			else if (i + y <= m) {
				step[i + y] = step[i] + 1;
			}
		}
	}
	return step[m] == INT_MAX ? -1 : step[m];
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << jump(n, m) << endl;
	return 0;
}