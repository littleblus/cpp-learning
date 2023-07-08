#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "myString.h"

int main() {
	littleblus::string s1("1234"), s2("124");
	if (s1 != s2)
		std::cout << "!=" << std::endl;

	return 0;
}