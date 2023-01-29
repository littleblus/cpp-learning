#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <climits>

int main() {
	int n, a, b;
	int money = INT_MAX;
	scanf("%d", &n);
	for (int i = 0; i < 3; i++) {
		scanf("%d%d", &a, &b);
		int num = n / a;
		if (n % a != 0)
			num++;
		if (num * b < money)
			money = num * b;
	}
	printf("%d\n", money);
	return 0;
}