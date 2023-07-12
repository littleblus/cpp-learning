#include "myVector.h"
#include <iostream>
#include <assert.h>

using namespace blus;

template<typename T>
void vector<T>::reserve(size_t n) {
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

template<typename T>
void vector<T>::resize(size_t n) {

}

template<typename T>
void vector<T>::push_back(const T& val) {
	if (_finish == _endOfStorage) {
		size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
		reserve(newCapacity);
	}
	*(_finish++) = val;
}

template<typename T>
T& vector<T>::operator[](size_t pos) {
	assert(pos < size());
	return _start[pos];
}

template<typename T>
const T& vector<T>::operator[](size_t pos) const {
	assert(pos < size());
	return _start[pos];
}