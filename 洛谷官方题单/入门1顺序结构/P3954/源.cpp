#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%.0f\n", a * 0.2 + b * 0.3 + c * 0.5);
	return 0;
}