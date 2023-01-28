#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int h, r, n = 0;
	const int dest = 20;
	scanf("%d%d", &h, &r);
	double v = 3.14 * 0.1 * r * 0.1 * r * 0.1 * h;
	double sum = 0;
	if (v > dest) {
		printf("1\n");
		return 0;
	}
	while (sum < dest) {
		sum += v;
		n++;
	}
	printf("%d\n", n);
	return 0;
}