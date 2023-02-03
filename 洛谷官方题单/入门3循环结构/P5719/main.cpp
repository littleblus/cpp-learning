#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int suma = 0, sumb = 0, counta = 0, countb = 0;
	for (int i = 1; i <= n; i++) {
		if (i % k == 0) {
			suma += i;
			counta++;
		}
		else {
			sumb += i;
			countb++;
		}
	}
	printf("%.1f %.1f\n", (double)suma / counta, (double)sumb / countb);
	return 0;
}