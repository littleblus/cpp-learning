#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> buf;
		for (auto& e : tokens) {
			if (e == "+" || e == "-" || e == "*" || e == "/") {
				int res = buf.top();
				buf.pop();
				switch (e[0]) {
				case '+':
					res += buf.top();
					break;
				case '-':
					res = buf.top() - res;
					break;
				case '*':
					res *= buf.top();
					break;
				case '/':
					res = buf.top() / res;
					break;
				}
				buf.pop();
				buf.push(res);
			}
			else {
				buf.push(stoi(e));
			}
		}
		return buf.top();
	}
};