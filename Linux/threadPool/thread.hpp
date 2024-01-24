#pragma once
#include <pthread.h>

using callback_t = void* (*)(void*);

class Thread {
public:
	Thread(callback_t cb, void* arg = nullptr)
		: _cb(cb)
		, _arg(arg)
		, _isRunning(false) {
	}

	void start() {
		pthread_create(&_tid, nullptr, _cb, _arg);
		_isRunning = true;
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
	}
private:
	callback_t _cb;
	pthread_t _tid;
	void* _arg;
	bool _isRunning;
};