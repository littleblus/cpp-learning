#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char a[100];
	cin >> a + 1;
	int len = strlen(a + 1);
	for (int i = len; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}