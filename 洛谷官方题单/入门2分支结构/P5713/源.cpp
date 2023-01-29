#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	int t1 = 5 * n;
	int t2 = 11 + 3 * n;
	if (t1 < t2)
		printf("Local\n");
	else
		printf("Luogu\n");
	return 0;
}