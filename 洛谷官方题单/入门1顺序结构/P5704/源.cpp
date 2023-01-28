#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cctype>
using namespace std;

int main() {
	char a;
	cin >> a;
	cout << (char)toupper(a) << endl;
	return 0;
}