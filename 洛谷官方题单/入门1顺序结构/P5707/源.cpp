#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int s, v;
	scanf("%d%d", &s, &v);
	int min = s / v;
	if (s % v != 0)//计算余数时间+1
		min++;
	//07:50是470分钟
	min = 470 - min;
	if (min < 0)//判断前一天出发的情况
		min = 1440 + min;
	//时间进制转换
	int hour = min / 60;
	min = min % 60;
	printf("%02d:%02d\n", hour, min);
	return 0;
}