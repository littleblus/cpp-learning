#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int a, b, c;
	char ori;
	scanf("%d-%d-%d-%c", &a, &b, &c, &ori);
	int check = 0;
	char num[10];
	sprintf(num, "%01d", a);
	sprintf(num + 1, "%03d", b);
	sprintf(num + 4, "%05d", c);
	for (int i = 1; i <= 9; i++) {
		int tmp = 0;
		tmp = num[i - 1] - '0';
		check += tmp * i;
	}
	check = check % 11;
	if (check == 10) {
		check = 'X';
	}
	else {
		check += '0';
	}
	if (check == ori) {
		printf("Right\n");
	}
	else {
		printf("%d-%d-%d-%c\n", a, b, c, check);
	}
	return 0;
}