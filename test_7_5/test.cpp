#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include "myString.h"

int main() {
	//std::string s1;
	//std::getline(std::cin, s1);

	littleblus::string s1("hello"), s2("hello");
	s1 += '\0', s2 += '\0';
	s1 += "world", s2 += "worldxxx";
	std::cout << (s1 < s2) << std::endl;
	
	//littleblus::string s1("hello world");
	//s1 += '\0';
	//s1 += "xxxxxxxxxxxxxxxxxxxxxxxx";
	//std::cout << s1 << std::endl;

	return 0;
}