#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int d, n;
	long long m = 0;
	scanf("%d%d", &d, &n);
	for (int i = d; i < n + d; i++) {
		if (i % 7 > 0 && i % 7 <= 5) {
			m += 250;
		}
	}
	printf("%lld\n", m);
	return 0;
}