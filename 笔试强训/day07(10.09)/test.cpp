#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 得到斐波那契数的最短步长
void next(int* arr) {
	int next = arr[0] + arr[1];
	arr[0] = arr[1];
	arr[1] = next;
}

int main() {
	int N;
	scanf("%d", &N);
	int arr[2]{ 1,1 };
	if (N <= 1) {
		printf("0\n");
		return 0;
	}
	while (arr[1] < N) {
		next(arr);
	}
	printf("%d\n", min(N - arr[0], arr[1] - N));

	return 0;
}



// 合法括号序列判断
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		stack<char> st;
		for (char ch : A) {
			if (ch == '(')
				st.emplace('(');
			else if (ch == ')') {
				if (st.empty())
					return false;
				else
					st.pop();
			}
			else
				return false;
		}
		return st.empty();
	}
};