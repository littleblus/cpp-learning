#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int a, b;
	int tmp = 8;
	int date = 0;
	for (int i = 0; i < 7; i++) {
		scanf("%d%d", &a, &b);
		if (a + b > tmp) {
			date = i + 1;
			tmp = a + b;
		}
	}
	printf("%d\n", date);
	return 0;
}