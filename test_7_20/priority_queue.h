#pragma once
#include <vector>

namespace blus {
	template<class T, class container = std::vector<T>, class compare = std::less<T>>
	class priority_queue {
		void adjustUp(int child) {
			compare _com;
			int parent = (child - 1) / 2;
			while (child > 0) {
				if (_com(_con[child], _con[parent])) {
					std::swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else {
					break;
				}
			}
		}

		void adjustDown(int parent) {
			compare _com;
			int child = parent * 2 + 1;// ×óº¢×Ó
			while (child < _con.size()) {
				if (child + 1 < _con.size() && _com(_con[child + 1], _con[child]))
					child++;
				if (_com(_con[child], _con[parent])) {
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else {
					break;
				}
			}
		}
	public:
		// constructor
		priority_queue() : _con(container()) {}
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last) {
			while (first != last) {
				_con.push_back(*first++);
			}
			for (int i = (int)(_con.size() - 2) / 2; i >= 0; i--) {
				adjustDown(i);
			}
		}
		
		// capacity
		bool empty() const { return _con.empty(); }
		size_t size() const { return _con.size(); }

		// access
		const T& top() const { return _con.front(); }
		void push(const T& val) {
			_con.push_back(val);
			adjustUp((int)_con.size() - 1);
		}
		void pop() {
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjustDown(0);
		}
	private:
		container _con;
	};
}