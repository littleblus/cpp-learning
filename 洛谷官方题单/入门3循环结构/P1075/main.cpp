#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	//找出n的最小约数，再用n除以这个数
	int i;
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			i = n / i;
			break;
		}
	}
	printf("%d\n", i);
	return 0;
}