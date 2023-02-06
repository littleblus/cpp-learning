#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int k;
	scanf("%d", &k);
	int daysOfCoins = 1;
	int sum = 0;
	int daysOfNow = 1;
	for (int i = 1; i <= k; i++) {
		if (daysOfNow > daysOfCoins) {
			daysOfNow = 1;
			daysOfCoins++;
		}
		sum += daysOfCoins;
		daysOfNow++;
	}
	printf("%d\n", sum);
	return 0;
}