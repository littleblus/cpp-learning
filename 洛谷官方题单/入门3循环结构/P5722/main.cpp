#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += i;
	printf("%d\n", sum);
	return 0;
}