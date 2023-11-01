#include <iostream>
#include "raii.h"

using namespace std;

class A {
public:
	~A() { cout << "A::~A()" << endl; }
};

int main() {
	blus::shared_ptr<A> sp(new A);
	blus::weak_ptr<A> wp(sp);
	return 0;
}