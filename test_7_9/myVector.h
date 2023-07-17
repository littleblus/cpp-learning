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
			, _endOfStorage(nullptr) {
		}

		// ����ʼ��
		vector(size_t n, const T& val = T()) {
			resize(n, val);
		}

		vector(int n, const T& val = T()) {
			resize(n, val);
		}

		template<typename inputIterator>
		vector(inputIterator first, inputIterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr) {
			while (first != last) {
				push_back(*first++);
			}
		}

		// ��������
		vector(const vector<T>& other)
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr) {
			*this = other;
		}

		// ��ֵ����
		vector<T>& operator=(const vector<T>& other) {
			if (this != &other) {
				size_t otherSize = other.size();
				reserve(otherSize);
				_finish = _start + otherSize;
				if (_start)
					//memcpy(_start, other._start, sizeof(T) * otherSize);// ע��ǳ����
					for (size_t i = 0; i < otherSize; i++) {
						_start[i] = other._start[i];
					}
			}
			return *this;
		}

		~vector() {
			delete[] _start;
		}

		size_t size() const { return _finish - _start; }
		size_t capacity() const { return _endOfStorage - _start; }
		
		// ������
		iterator begin() { return _start; }
		const_iterator begin() const { return _start; }
		iterator end() { return _finish; }
		const_iterator end() const { return _finish; }

		void swap(vector<T>& val) {
			std::swap(_start, val._start);
			std::swap(_finish, val._finish);
			std::swap(_endOfStorage, val._endOfStorage);
		}

		void reserve(size_t n) {
			if (n > capacity()) {
				T* tmp = new T[n];
				size_t oldsize = size();
				if (_start) {
					//memcpy(tmp, _start, sizeof(T) * oldsize);// ǳ����������
					for (size_t i = 0; i < size(); i++) {
						tmp[i] = _start[i];
					}
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

		bool empty() {
			return (_finish - _start) == 0;
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
			pos = _start + len;// ���������ʧЧ
			memmove(pos + 1, pos, (_finish - pos) * sizeof(T));
			*pos = val;
			_finish++;

			return pos;
		}

		iterator erase(iterator pos) {
			assert(_start <= pos && pos < _finish);
			memmove(pos, pos + 1, (_finish - pos - 1) * sizeof(T));
			_finish--;

			return pos;
		}

		T& operator[](size_t pos) {
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const {
			assert(pos < size());
			return _start[pos];
		}

		bool operator==(const vector& other) const {
			if (size() != other.size())
				return false;
			for (size_t i = 0; i < size(); i++) {
				if (_start[i] != other._start[i])
					return false;
			}
			return true;
		}
	private:
		iterator _start;// ָ�����ݿ鿪ʼ
		iterator _finish;// ָ����Ч���ݵ�β
		iterator _endOfStorage;// ָ��洢������β

		void checkCapacity(size_t add = 0) {
			size_t newCapacity = capacity();
			if (_finish + add >= _endOfStorage) {
				if (capacity() == 0) {
					newCapacity = 4;// ��ʼ�ռ��С
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