#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	const float price = 1.9;
	int a, b;
	scanf("%d%d", &a, &b);
	float money = a + (float)b / 10;
	int n = 0;
	while (money >= 0) {
		money -= price;
		n++;
	}
	printf("%d\n", --n);
	return 0;
}