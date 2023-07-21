#include <stack>
#include <vector>
using namespace std;

// ��Сջ
//https://leetcode-cn.com/problems/min-stack/
class MinStack {
public:
	MinStack() {
		_st = stack<int>();
		_minst = stack<int>();
	}

	void push(int val) {
		_st.push(val);
		if (val <= (_minst.empty() ? INT_MAX : _minst.top()))
			_minst.push(val);
	}

	void pop() {
		if (_minst.top() == _st.top()) {
			_minst.pop();
		}
		_st.pop();
	}

	int top() {
		return _st.top();
	}

	int getMin() {
		return _minst.top();
	}
private:
	stack<int> _st;
	stack<int> _minst;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



// ջ�ĵ���ѹ������
//https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&&tqId=11174&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	/**
	 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	 *
	 *
	 * @param pushV int����vector
	 * @param popV int����vector
	 * @return bool������
	 */
	bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
		size_t i = 0;
		stack<int> st;
		for (int e : pushV) {
			st.push(e);
			while (!st.empty() && st.top() == popV[i]) {
				// ��ջ
				st.pop();
				i++;
			}
		}
		if (i == popV.size())
			return true;
		else
			return false;
	}
};

int main() {
	vector<int> v1{1, 2, 3, 4, 5 };
	vector<int> v2{4, 5, 3, 2, 1 };
	Solution s;
	s.IsPopOrder(v1, v2);
}