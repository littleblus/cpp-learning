#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int x = 100;
	int k = 1;
	int sum = 0;
	int n = 0;
	scanf("%d", &n);
	n /= 7 * 52;
	//x + 3k = n
	//nÈ¡×î´ó£¬Èôk=1 x = n - 3
	if (n > 103) {
		do {
			x = n - 3 * k;
			k++;
		} while (x > 100);
		printf("%d\n%d\n", x, --k);
	}
	else {
		printf("%d\n%d\n", n - 3, 1);
	}
	return 0;
}