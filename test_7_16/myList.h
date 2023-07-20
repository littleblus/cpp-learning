#pragma once
#include <assert.h>

namespace blus {
	template<typename T>
	struct list_node {
		list_node<T>* _prev;
		list_node<T>* _next;
		T _data;

		list_node(const T& val = T()) :_prev(nullptr), _next(nullptr), _data(val) {}
		list_node(const T& val, list_node<T>* prev, list_node<T>* next)
			:_prev(prev), _next(next), _data(val) {}
	};

	template<typename T>
	class list {
	public:
		// list construct
		list() {
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		list(const list<T>& other) { 
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			*this = other; 
		}
		list<T>& operator=(const list<T>& other) {
			Node* cur = other._head->_next;
			while (cur != other._head) {
				push_back(cur->_data);
				cur = cur->_next;
			}
			return *this;
		}
		~list() {
			if (empty()) {
				delete _head;
			}
			else {
				Node* cur(_head), * next(_head->_next);
				while (next != _head) {
					delete cur;
					cur = next;
					next = next->_next;
				}
			}
		}

		// list iterator
		template<typename T>
		struct __list_iterator {
			typedef list_node<T> Node;
			Node* _node;

			__list_iterator(Node* node) :_node(node) {}
			T& operator*() { return _node->_data; }
			__list_iterator<T>& operator++() {
				_node = _node->_next;
				return *this;
			}
			__list_iterator<T> operator++(int) {
				auto tmp = *this;
				_node = _node->_next;
				return tmp;
			}
			__list_iterator<T>& operator--() {
				_node = _node->_prev;
				return *this;
			}
			__list_iterator<T> operator--(int) {
				auto tmp = *this;
				_node = _node->_prev;
				return tmp;
			}

			bool operator!=(const __list_iterator<T>& other) const { return _node != other._node; }
		};
		typedef __list_iterator<T> iterator;
		//typedef const __list_iterator<T> const_iterator;  这样设计const迭代器行吗？
		iterator begin() { return _head->_next; }
		iterator end() { return _head; }

		// elements access
		T& front() {
			assert(!empty());
			return _head->_next->_data;
		}
		const T& front() const {
			assert(!empty());
			return _head->_next->_data;
		}
		T& back() {
			assert(!empty());
			return _head->_prev->_data;
		}
		const T& back() const {
			assert(!empty());
			return _head->_prev->_data;
		}

		// list capacity
		bool empty() const { return _head->_next == _head; }
		size_t size() const {
			size_t sz = 0;
			Node* cur = _head->_next;
			while (cur != _head) {
				sz++;
				cur = cur->_next;
			}
			return sz;
		}

		// list modify
		void push_back(const T& val) { insert(_head, val); }
		void push_front(const T& val) { insert(_head->_next, val); }
		void pop_back() { erase(_head->_prev); }
		void pop_front() { erase(_head->_next); }
		iterator insert(iterator pos, const T& val) {
			Node* newNode = new Node(val, pos._node->_prev, pos._node);
			pos._node->_prev->_next = newNode;
			pos._node->_prev = newNode;
			return pos;
		}
		iterator erase(iterator pos) {
			assert(!empty());
			Node* next = pos._node->_next;
			pos._node->_prev->_next = next;
			next->_prev = pos._node->_prev;
			delete pos._node;
			return next;
		}

	private:
		typedef list_node<T> Node;
		Node* _head;
	};
}