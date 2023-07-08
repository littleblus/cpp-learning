#include "myString.h"
#include <assert.h>
#include <algorithm>
using namespace littleblus;

string& string::operator=(const string& other) {
	if (this != &other) {
		delete[] _str;
		_size = other._size;
		_capacity = _size;
		_str = new char[_capacity + 1];
		strcpy(_str, other._str);
	}
	return *this;
}

char& string::operator[](size_t pos) {
	assert(pos < _size);
	return _str[pos];
}

const char& string::operator[](size_t pos) const {
	assert(pos < _size);
	return _str[pos];
}

void string::reserve(size_t n) {
	if (n > _capacity) {
		char* tmp = new char[n + 1];
		strcpy(tmp, _str);
		delete[] _str;
		_str = tmp;
		_capacity = n;
	}
}

void string::push_back(char ch) {
	checkCapacity(1);
	_str[_size++] = ch;
	_str[_size] = '\0';
}

void string::append(const char* str) {
	size_t len = strlen(str);
	checkCapacity(len);
	strcpy(_str + _size, str);
	_size += len;
}

string& string::operator+=(char ch) {
	push_back(ch);
	return *this;
}

string& string::operator+=(const char* str) {
	append(str);
	return *this;
}

void string::insert(size_t pos, size_t n, char ch) {
	assert(pos <= _size);
	checkCapacity(n);
	memmove(_str + pos + n, _str + pos, _size - pos + 1);
	memset(_str + pos, ch, n);
	_size += n;
}

void string::insert(size_t pos, const char* str) {
	assert(pos <= _size);
	size_t len = strlen(str);
	checkCapacity(len);
	memmove(_str + pos + len, _str + pos, _size - pos + 1);
	memcpy(_str + pos, str, len);
	_size += len;
}

void string::erase(size_t pos, size_t len) {
	assert(pos <= _size);
	if (len == npos || pos + len >= _size) {
		_str[pos] = '\0';
		_size = pos;
	}
	else {
		memmove(_str + pos, _str + pos + len, _size - (pos + len) + 1);
		_size -= len;
	}
}

size_t string::find(char ch, size_t pos) {
	assert(pos < _size);
	for (size_t i = pos; i < _size; i++) {
		if (_str[i] == ch)
			return i;
	}
	return npos;
}

size_t string::find(const char* str, size_t pos) {
	// BM匹配
	assert(pos < _size);
	size_t patLen = strlen(str);
	size_t txtLen = _size;
	if (patLen == 0 || patLen > txtLen)
		return npos;
	// 构建坏字符规则表
	int badChar[256];
	for (int i = 0; i < 256; i++)
		badChar[i] = (int)patLen;
	for (int i = 0; i < patLen - 1; i++)
		badChar[(unsigned char)str[i]] = (int)patLen - i - 1;
	// 根据坏字符规则进行匹配
	int s = (int)pos;
	while (s <= txtLen - patLen) {
		int j = (int)patLen - 1;
		// 逆向比较模式串和文本串
		while (j >= 0 && str[j] == _str[s + j])
			--j;
		if (j < 0)
			return s;
		s += std::max(1, j - badChar[(unsigned char)_str[s + j]]);
	}
	return npos;
}

string string::substr(size_t pos, size_t len) const {
	assert(pos <= _size);
	if (len == npos || pos + len > _size)
		len = _size - pos;
	string ret;
	ret.reserve(len);
	for (size_t i = pos; i < pos + len; i++) {
		ret += _str[i];
	}
	return ret;
}

bool string::operator<(const string& s) {
	for (size_t i = 0; i < _size && i < s._size; i++) {
		if (_str[i] < s[i])
			return true;
		else if (_str[i] > s._str[i])
			return false;
	}
	return false;
}

bool string::operator<=(const string& s) {
	return *this < s || *this == s;
}

bool string::operator>(const string& s) {
	return !(*this <= s);
}

bool string::operator>=(const string& s) {
	return !(*this < s);
}

bool string::operator==(const string& s) {
	if (_size != s._size)
		return false;
	else {
		for (size_t i = 0; i < _size; i++) {
			if (_str[i] != s._str[i])
				return false;
		}
		return true;
	}
}

bool string::operator!=(const string& s) {
	return !(*this == s);
}

void string::checkCapacity(size_t addLen) {
	size_t space = _size + addLen;
	if (space > _capacity) {
		//计算对齐
		space += 4 - space % 4;
		//二倍扩容
		reserve(space * 2);
	}
}