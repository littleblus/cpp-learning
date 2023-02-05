#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int n, x, count = 0;
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++) {
		int tmp = i;
		while (tmp > 9) {
			if (tmp % 10 == x)
				count++;
			tmp /= 10;
		}
		if (tmp % 10 == x)
			count++;
	}
	printf("%d\n", count);
	return 0;
}