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
	class list {// 类模板在类中使用时既可以写类名又可以写类型
	public:
		// list construct
		void emptyInit() {
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}
		list() { emptyInit(); }
		list(const list<T>& other) { 
			emptyInit();
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
			clear();
			delete _head;
		}

		// list iterator
		template<typename T, typename Ref, typename Ptr>
		struct __list_iterator {
			typedef list_node<T> Node;
			typedef __list_iterator<typename T, typename Ref, typename Ptr> self;
			Node* _node;

			__list_iterator(Node* node) :_node(node) {}
			Ref operator*() const { return _node->_data; }
			Ptr operator->() const { return &(_node->_data); }
			self& operator++() {
				_node = _node->_next;
				return *this;
			}
			self operator++(int) {
				auto tmp = *this;
				_node = _node->_next;
				return tmp;
			}

			bool operator!=(const self& other) const { return _node != other._node; }
		};
		typedef __list_iterator<T, T&, T*> iterator;
		//typedef const __list_iterator<T> const_iterator;  这样设计const迭代器行吗？
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		iterator begin() { return _head->_next; }
		const_iterator begin() const { return _head->_next; }
		iterator end() { return _head; }
		const_iterator end() const { return _head; }

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
		size_t size() const { return _size; }

		// list modify
		void push_back(const T& val) { insert(_head, val); }
		void push_front(const T& val) { insert(_head->_next, val); }
		void pop_back() { erase(_head->_prev); }
		void pop_front() { erase(_head->_next); }
		iterator insert(iterator pos, const T& val) {
			Node* newNode = new Node(val, pos._node->_prev, pos._node);
			pos._node->_prev->_next = newNode;
			pos._node->_prev = newNode;
			_size++;
			return newNode;
		}
		iterator erase(iterator pos) {
			assert(!empty() && pos != end());
			Node* next = pos._node->_next;
			pos._node->_prev->_next = next;
			next->_prev = pos._node->_prev;
			delete pos._node;
			_size--;
			return next;
		}
		void clear() { while (!empty()) pop_back(); }
		void swap(list<T>& other) {
			std::swap(_head, other._head);
			std::swap(_size, other._size);
		}

	private:
		typedef list_node<T> Node;
		Node* _head;
		size_t _size;
	};
}