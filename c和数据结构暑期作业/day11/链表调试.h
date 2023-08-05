#pragma once
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* buildList(std::vector<int>& v) {
	ListNode* guard = new ListNode(-1), * cur(guard);
	for (auto e : v) {
		cur->next = new ListNode(e);
		cur = cur->next;
	}
	cur = guard->next;
	delete(guard);
	return cur;
}