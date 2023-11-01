#pragma once

namespace blus {
	template<class T>
	class auto_ptr {
	public:
		explicit auto_ptr(T* ptr) :_ptr(ptr) {}
		~auto_ptr() { delete _ptr; }
		T* operator->() { return _ptr; }
		T& operator*() { return *_ptr; }

		auto_ptr(auto_ptr& other) : _ptr(other) {
			other._ptr = nullptr;
		}

		auto_ptr& operator=(auto_ptr& other) {
			if (this != &other) {
				delete _ptr;
				_ptr = other._ptr;
				other._ptr = nullptr;
			}
			return *this;
		}
	private:
		T* _ptr;
	};

	template<class T>
	class unique_ptr {
	public:
		explicit unique_ptr(T* ptr) :_ptr(ptr) {}
		~unique_ptr() { delete _ptr; }
		T* operator->() { return _ptr; }
		T& operator*() { return *_ptr; }
		unique_ptr(const unique_ptr&) = delete;
		unique_ptr& operator=(const unique_ptr&) = delete;
	private:
		T* _ptr;
	};

	template<class T>
	class weak_ptr {
	public:
		weak_ptr() : _ptr(nullptr) {}
		weak_ptr(const shared_ptr<T>& other) { _ptr = other._ptr; }
		weak_ptr& operator=(const shared_ptr<T>& other) {
			_ptr = other._ptr;
			return *this;
		}
		T* operator->() { return _ptr; }
		T& operator*() { return *_ptr; }
	private:
		T*_ptr;
	};

	template<class T>
	class shared_ptr {
	public:
		friend class weak_ptr<T>;

		explicit shared_ptr(T* ptr) : _ptr(ptr) {
			_refCount = new RefCount();
			_refCount->_count = 1;
		}

		~shared_ptr() {
			--_refCount->_count;
			if (_refCount->_count == 0) {
				delete _ptr;
				delete _refCount;
			}
		}

		shared_ptr(const shared_ptr& other) : _ptr(other._ptr), _refCount(other._refCount) {
			++_refCount->_count;
		}

		shared_ptr& operator=(const shared_ptr& other) {
			if (this != &other) {
				--_refCount->_count; // 先把自己的引用计数减1
				if (_refCount->_count == 0) {
					delete _ptr;
					delete _refCount;
				}
				_ptr = other._ptr;
				_refCount = other._refCount;
				++_refCount->_count;
			}
			return *this;
		}

	private:
		struct RefCount {
			RefCount() :_count(0) {}
			int _count;
		};

		T* _ptr;
		RefCount* _refCount;
	};
}