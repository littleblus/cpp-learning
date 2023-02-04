#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int a, tmp, count = 1;
	scanf("%d", &a);
	while (a > 1) {
		a = a / 2;
		count++;
	}
	printf("%d\n", count);
	return 0;
}