#pragma once
#include <pthread.h>
#include <condition_variable>
#include <mutex>

using callback_t = void* (*)(void*);

void* _defaultcb(void*) { return nullptr; }

class Thread {
public:
	Thread(callback_t cb = _defaultcb, void* arg = nullptr)
		: _cb(cb)
		, _arg(arg)
		, _isRunning(false) {
		_cond = new std::condition_variable();
		_mutex = new std::mutex();
	}

	Thread(const Thread& rhs)
		: _cb(rhs._cb)
		, _arg(rhs._arg)
		, _isRunning(false) {
		_cond = new std::condition_variable();
		_mutex = new std::mutex();
	}

	Thread& operator=(const Thread& rhs) {
		if (this != &rhs) {
			_cb = rhs._cb;
			_arg = rhs._arg;
			_isRunning = false;
			_cond = new std::condition_variable();
			_mutex = new std::mutex();
		}
		return *this;
	}

	static void* ThreadFunc(void* arg) {
		Thread* thread = static_cast<Thread*>(arg);
		{
			std::unique_lock<std::mutex> lock(*thread->_mutex);
			while (!thread->_isRunning) {
				thread->_cond->wait(lock);
			}
		}
		return thread->_cb(thread->_arg);
	}

	void create() {
		pthread_create(&_tid, nullptr, ThreadFunc, this);
	}

	void start(callback_t cb = _defaultcb, void* arg = nullptr) {
		if (cb != _defaultcb) _cb = cb;
		if (arg != nullptr) _arg = arg;
		{
			std::lock_guard<std::mutex> lock(*_mutex);
			_isRunning = true;
		}
		_cond->notify_one();
	}

	void join(void** ret = nullptr) {
		if (_isRunning) {
			pthread_join(_tid, ret);
			_isRunning = false;
		}
	}

	~Thread() {
		if (_isRunning) {
			pthread_detach(_tid);
			_isRunning = false;
		}
		delete _cond;
		delete _mutex;
	}
private:
	callback_t _cb;
	pthread_t _tid;
	void* _arg;
	bool _isRunning;
	std::condition_variable* _cond;
	std::mutex* _mutex;
};