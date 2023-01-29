#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int x, n = 0, i;
	double v1 = (4.0 / 3) * 3.141593 * pow(4, 3);
	double v2 = (4.0 / 3) * 3.141593 * pow(10, 3);
	scanf("%d", &x);
	switch (x) {
	case 1:
		printf("I love Luogu!\n");
		break;
	case 2:
		printf("6 4\n");
		break;
	case 3:
		printf("3\n");
		printf("12\n");
		printf("2\n");
		break;
	case 4:
		printf("%.3f\n", 500 / 3.0);
		break;
	case 5:
		printf("%d\n", (260 + 220) / (12 + 20));
		break;
	case 6:
		cout << sqrt(6 * 6 + 9 * 9) << endl;
		break;
	case 7:
		printf("110\n");
		printf("90\n");
		printf("0\n");
		break;
	case 8:
		cout << 2 * 3.141593 * 5 << endl;
		cout << 3.141593 * 5 * 5 << endl;
		cout << (4 / 3.0) * 3.141593 * 5 * 5 * 5 << endl;
		break;
	case 9:
		while (++n) {
			int tmp = n;
			int flag = 0;
			for (int i = 0; i < 3; i++) {
				if (tmp % 2 != 0) {
					flag = 1;
					break;
				}
				tmp /= 2;
				tmp--;
			}
			if (tmp == 1 && flag == 0)
				break;
		}
		printf("%d\n", n);
		break;
	case 10:
		printf("9\n");
		break;
	case 11:
		cout << 100.0 / (8 - 5) << endl;
		break;
	case 12:
		printf("%d\n", 'M' - 'A' + 1);
		printf("%c\n", 'A' + 18 - 1);
		break;
	case 13:
		printf("%.0f\n", pow(v1 + v2, 1.0 / 3));
		break;
	case 14:
		for (i = 1, n = (110 - 1) + 10; i <= 120; i++) {
			if (i * n >= 3500)
				break;
			n--;
		}
		printf("%d\n", i);
		break;
	}
	return 0;
}