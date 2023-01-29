#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int is_leap_year(const int year) {
	if (year % 4 == 0 && year % 100 != 0)
		return 1;
	if (year % 400 == 0)
		return 1;
	return 0;
}

int main() {
	int year = 0;
	int month = 0;
	int flag = 0;
	while (scanf("%d %d", &year, &month) != EOF) {
		int ret = 0;
		switch (month) {
		case 1:
			ret = 31;
			break;
		case 2:
			flag = is_leap_year(year);
			if (flag == 1) {
				ret = 29;
			}
			else
				ret = 28;
			break;
		case 3:
			ret = 31;
			break;
		case 4:
			ret = 30;
			break;
		case 5:
			ret = 31;
			break;
		case 6:
			ret = 30;
			break;
		case 7:
			ret = 31;
			break;
		case 8:
			ret = 31;
			break;
		case 9:
			ret = 30;
			break;
		case 10:
			ret = 31;
			break;
		case 11:
			ret = 30;
			break;
		case 12:
			ret = 31;
			break;
		}
		printf("%d\n", ret);
	}
	return 0;
}