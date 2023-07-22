#pragma once
#include <assert.h>
#include <deque>

namespace blus {
	template<class T, class container = std::deque<T>>
	class stack {
	public:
		void push(const T& val) {
			_con.push_back(val);
		}

		void pop() {
			_con.pop_back();
		}

		T& top() {
			return _con.back();
		}

		size_t size() const {
			return _con.size();
		}

		bool empty() const {
			return _con.empty();
		}
	private:
		container _con;
	};

	template<class T, class container = std::deque<T>>
	class queue {
	public:
		void push(const T& val) {
			_con.push_back(val);
		}

		void pop() {
			_con.pop_front();
		}

		T& front() {
			return _con.front();
		}

		size_t size() const {
			return _con.size();
		}

		bool empty() const {
			return _con.empty();
		}
	private:
		container _con;
	};
}