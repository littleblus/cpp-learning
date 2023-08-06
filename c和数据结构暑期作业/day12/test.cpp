#include <stack>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

// �������
//https://leetcode.cn/problems/sum-lists-lcci/

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// ���Ƿ��ŷŵ�
		int num1, num2, carry;
		num1 = num2 = carry = 0;
		ListNode* cur1(l1), * cur2(l2), * guard(new ListNode(-1)), * retCur(guard);
		while (cur1 && cur2) {
			int sum = cur1->val + cur2->val + carry;
			carry = sum > 9 ? 1 : 0;
			retCur->next = new ListNode(sum % 10);
			retCur = retCur->next;
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		// �ж��ĸ��ߵ���ĩβ,��cur1����
		if (cur2)
			cur1 = cur2;
		while (cur1) {
			int sum = cur1->val + carry;
			retCur->next = new ListNode(sum % 10);
			carry = sum > 9 ? 1 : 0;
			retCur = retCur->next;
			cur1 = cur1->next;
		}
		// ��������λ
		if (carry)
			retCur->next = new ListNode(1);
		retCur = guard->next;
		delete guard;
		return retCur;
	}
};



// ���ŵ����Ƕ�����
//https://leetcode.cn/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
	int maxDepth(string s) {
		stack<char> st;
		int res = 0;
		for (auto e : s) {
			if (e == '(')
				st.push('(');
			else if (e == ')')
				st.pop();
			res = st.size() > res ? st.size() : res;
		}
		return res;
	}
};