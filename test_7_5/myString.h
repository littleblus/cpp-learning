#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

namespace littleblus {
	class string {
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		static const size_t npos = -1;

		string(const char* str = "") {
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s) {
			_size = s._size;
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		~string() {
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		string& operator=(const string& other);

		//�����ַ���ָ��
		const char* c_str() const { return _str; }

		size_t size() const { return _size; }
		size_t capacity() const { return _capacity; }

		//����
		char& operator[](size_t pos);
		const char& operator[](size_t pos) const;

		iterator begin() { return _str; }
		iterator end() { return _str + _size; }
		const_iterator begin() const { return _str; }
		const_iterator end() const { return _str + _size; }
		
		//�޸Ŀռ�
		void reserve(size_t n);//nָ������Ч�ַ��ĸ���

		//��
		void push_back(char ch);
		void append(const char* str);
		string& operator+=(char ch);
		string& operator+=(const char* str);
		void insert(size_t pos, size_t n, char ch);
		void insert(size_t pos, const char* str);

		//ɾ
		void erase(size_t pos, size_t len = npos);

		//��
		size_t find(char ch, size_t pos = 0);
		size_t find(const char* str, size_t pos = 0);
		string substr(size_t pos = 0, size_t len = npos) const;

		//��ϵ���������
		bool operator<(const string& s);
		bool operator<=(const string& s);
		bool operator>(const string& s);
		bool operator>=(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);

	private:
		char* _str;
		size_t _capacity;
		size_t _size;

		void checkCapacity(size_t addLen);
	};
}