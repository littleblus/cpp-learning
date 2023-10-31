#include <iostream>

using namespace std;

// 设计一个只能在堆上创建对象的类
class heapOnly {
public:
	static heapOnly* getHeapOnly(int n = 0) {
		return new heapOnly(n);
	}

	static void delHeapOnly(heapOnly* p) {
		delete p;
	}

	int show() { return m_a; }
	heapOnly(int n) : m_a(n) {}
private:
	int m_a;

	heapOnly(const heapOnly& other) = delete;
	~heapOnly() {}
};

// 设计一个只能在栈上生成对象的类
class stackOnly {
public:
	static stackOnly getStackOnly(int n = 0) {
		return stackOnly(n);
	}

	int show() { return m_a; }
	void* operator new(size_t size) = delete;
	void operator delete(void* p) = delete;
private:
	int m_a;

	stackOnly(int n) : m_a(n) {}
};

// 设计一个不能拷贝的类
class banCopy {
public:
	banCopy(int n = 0) : m_a(n) {}
	banCopy(const banCopy& other) = delete;
	banCopy& operator=(const banCopy& other) = delete;
private:
	int m_a;
};

// 设计一个类，不能被继承
class noChild final {
private:
	int m_a;
};

// 单例模式（饿汉）
// 优点：好写
// 缺点：启动速度较慢，需要在使用前声明
class eagerSingleton {
public:
	void modify(int n) { m_a = n; }
	int show() { return m_a; }
	static eagerSingleton* getInstance() { return &_m; }
private:
	static eagerSingleton _m;
	int m_a;
	
	eagerSingleton() {}
	eagerSingleton(const eagerSingleton& other) = delete;
	eagerSingleton& operator=(const eagerSingleton& other) = delete;
};
eagerSingleton eagerSingleton::_m;

// 单例模式（懒汉） 
// 优点：按需构造
// 缺点：比较复杂
class lazySingleton {
	static lazySingleton* getInstance() {
		if (_p == nullptr) {
			_p = new lazySingleton();
		}
		else {
			return _p;
		}
	}
private:
	static lazySingleton* _p;
	int m_a;

	lazySingleton(int n = 0) : m_a(n) {}

	lazySingleton(const lazySingleton& other) = delete;
	lazySingleton& operator=(const lazySingleton& other) = delete;
};
lazySingleton* lazySingleton::_p = nullptr;

void testHeapOnly() {
	heapOnly* pa = heapOnly::getHeapOnly(1);
	cout << pa->show() << endl;
	heapOnly::delHeapOnly(pa);
}

void testStackOnly() {
	stackOnly a = stackOnly::getStackOnly(2);
	cout << a.show() << endl;
}

void testEagerSingleton() {
	eagerSingleton::getInstance()->modify(3);
	cout << eagerSingleton::getInstance()->show() << endl;
}

int main() {
	//testHeapOnly();
	//testStackOnly();
	testEagerSingleton();
	return 0;
}