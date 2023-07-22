#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

class LRUCache {
public:
	LRUCache(int capacity) {
		_capacity = capacity;
		_head = new node();
		_head->_next = _head;
		_head->_prev = _head;
		_map = unordered_map<int, node*>();
	}

	int get(int key) {
		auto it = _map.find(key);
		if (it == _map.end())
			return -1;
		else {
			moveToTail(it->second);
			return it->second->_val;
		}
	}

	void put(int key, int value) {
		auto it = _map.find(key);
		if (it == _map.end()) {
			push(key, value);
		}
		else {
			moveToTail(it->second);
			it->second->_val = value;
		}
	}
private:
	size_t _capacity;
	struct node {
		int _key;
		int _val;
		node* _prev;
		node* _next;
		node(int k = 0, int v = 0) : _key(k), _val(v) {}
	};
	unordered_map<int, node*> _map;
	node* _head;

	void push(int k, int v) {
		if (_map.size() == _capacity) {
			int delK = _head->_next->_key;
			node* del = _head->_next;
			_head->_next = del->_next;
			_head->_next->_prev = _head;
			delete del;
			_map.erase(delK);
		}
		node* add = new node(k, v);
		add->_next = _head;
		add->_prev = _head->_prev;
		_head->_prev = add;
		add->_prev->_next = add;
		_map.insert({ k, add });
	}

	void moveToTail(node* cur) {
		if (cur->_next == _head)
			return;
		node* tailnode = _head->_prev;
		cur->_prev->_next = cur->_next;
		cur->_next->_prev = cur->_prev;
		cur->_next = _head;
		cur->_prev = tailnode;
		tailnode->_next = cur;
		_head->_prev = cur;
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// ["LRUCache","put","put","get","put","get","put","get","get","get"]
// [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
//int main() {
//	LRUCache l(2);
//	l.put(1, 1);
//	l.put(2, 2);
//	cout << l.get(1) << ' ';
//	l.put(3, 3);
//	cout << l.get(2) << ' ';
//	l.put(4, 4);
//	cout << l.get(1) << ' ';
//	cout << l.get(3) << ' ';
//	cout << l.get(4) << ' ';
//
//	return 0;
//}

// ["LRUCache","put","get","put","get","get"]
// [[1],[2,1],[2],[3,2],[2],[3]]
int main() {
	LRUCache l(1);
	l.put(2, 1);
	cout << l.get(2) << ' ';
	l.put(3, 2);
	cout << l.get(2) << ' ';
	cout << l.get(3) << ' ';

	return 0;
}