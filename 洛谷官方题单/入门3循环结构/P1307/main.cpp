#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <cmath>

int main() {
	int num;
	scanf("%d", &num);
	int ret = 0;
	int flag = 1;
	if (num < 0) {
		flag = -1;
		num *= -1;
	}
	int tmp = num;
	int i = 0;
	while (tmp > 9) {//¼ÆËãÎ»Êý
		i++;
		tmp /= 10;
	}
	while (num > 9) {
		ret += (num % 10) * (int)pow(10, i);
		num /= 10;
		i--;
	}
	ret += num;
	ret *= flag;
	printf("%d\n", ret);
	return 0;
}