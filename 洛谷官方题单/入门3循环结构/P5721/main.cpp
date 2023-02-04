#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	int k = n, j = 1;
	for (int i = 0; i < n; i++) {
		for (int count = 0; count < k; count++) {
			printf("%02d", j);
			j++;
		}
		printf("\n");
		k--;
	}
	return 0;
}