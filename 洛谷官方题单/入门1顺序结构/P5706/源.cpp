#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	float a;
	int b;
	scanf("%f%d", &a, &b);
	printf("%.3f\n%d\n", a / b, b * 2);
	return 0;
}