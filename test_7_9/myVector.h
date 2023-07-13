#pragma once

#include <assert.h>
#include <iostream>

namespace blus {
	template<typename T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}

		// 拷贝构造
		vector(const vector<T>& other)
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			*this = other;
 		}

		// 赋值重载
		vector<T>& operator=(const vector<T>& other) {
			if (this != &other) {
				size_t otherSize = other.size();
				reserve(otherSize);
				_finish = _start + otherSize;
				if (_start)
					memcpy(_start, other._start, sizeof(T) * otherSize);
			}
			return *this;
		}

		~vector() {
			delete[] _start;
		}

		size_t size() const { return _finish - _start; }
		size_t capacity() const { return _endOfStorage - _start; }
		
		// 迭代器
		iterator begin() { return _start; }
		const_iterator begin() const { return _start; }
		iterator end() { return _finish; }
		const_iterator end() const { return _finish; }

		void reserve(size_t n) {
			if (n > capacity()) {
				T* tmp = new T[n];
				size_t oldsize = size();
				if (_start) {
					memcpy(tmp, _start, sizeof(T) * oldsize);
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + oldsize;
				_endOfStorage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T()) {
			if (n > size()) {
				size_t add = n - size();
				checkCapacity(add);
				while (add--) {
					*_finish++ = val;
				}
			}
			else {
				_finish = _start + n;
			}
		}

		void push_back(const T& val) {
			checkCapacity();
			*_finish++ = val;
		}

		void pop_back() {
			assert(_finish - 1 >= _start);
			_finish--;
		}

		iterator insert(iterator pos, const T& val) {
			assert(_start <= pos && pos <= _finish);
			size_t len = pos - _start;
			checkCapacity();
			pos = _start + len;// 解决迭代器失效
			memmove(pos + 1, pos, (_finish - pos) * sizeof(T));
			*pos = val;
			_finish++;

			return pos;
		}

		iterator erase(iterator pos) {

		}

		T& operator[](size_t pos) {
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const {
			assert(pos < size());
			return _start[pos];
		}
	private:
		iterator _start;// 指向数据块开始
		iterator _finish;// 指向有效数据的尾
		iterator _endOfStorage;// 指向存储容量的尾

		void checkCapacity(size_t add = 0) {
			size_t newCapacity = capacity();
			if (_finish + add >= _endOfStorage) {
				if (capacity() == 0) {
					newCapacity = 4;// 初始空间大小
					reserve(newCapacity);
					if (_finish + add < _endOfStorage)
						return;
				}
				while (size() + add >= newCapacity) {
					newCapacity <<= 1;
				}
				reserve(newCapacity);
			}
		}
	};
}