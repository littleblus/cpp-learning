#pragma once

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

		size_t size() const { return _finish - _start; }
		size_t capacity() const { return _endOfStorage - _start; }
		
		// µü´úÆ÷
		iterator begin() { return _start };
		const_iterator begin() const { return _start };
		iterator end() { return _finish };
		const_iterator end() const { return _finish };

		void reserve(size_t n);
		void resize(size_t n);

		void push_back(const T& val);

		T& operator[](size_t pos);
		const T& operator[](size_t pos) const;
	private:
		iterator _start;
		iterator _finish;
		iterator _endOfStorage;
	};
}