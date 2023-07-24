#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

// 逆波兰表达式求值
//https://leetcode.cn/problems/evaluate-reverse-polish-notation/

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> buf;
		for (auto& e : tokens) {
			if (e == "+" || e == "-" || e == "*" || e == "/") {
				int res;
				switch (e[0]) {
				case '+':
					res = buf.top();
					buf.pop();
					res += buf.top();
					buf.pop();
					buf.push(res);
					break;
				case '-':
					res = -buf.top();
					buf.pop();
					res += buf.top();
					buf.pop();
					buf.push(res);
					break;
				case '*':
					res = buf.top();
					buf.pop();
					res *= buf.top();
					buf.pop();
					buf.push(res);
					break;
				case '/':
					res = buf.top();
					buf.pop();
					res = buf.top() / res;
					buf.pop();
					buf.push(res);
					break;
				}
			}
			else {
				buf.push(stoi(e));
			}
		}
		return buf.top();
	}
};