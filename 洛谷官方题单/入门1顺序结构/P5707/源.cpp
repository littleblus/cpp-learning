#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int s, v;
	scanf("%d%d", &s, &v);
	int min = s / v;
	if (s % v != 0)//��������ʱ��+1
		min++;
	//07:50��470����
	min = 470 - min;
	if (min < 0)//�ж�ǰһ����������
		min = 1440 + min;
	//ʱ�����ת��
	int hour = min / 60;
	min = min % 60;
	printf("%02d:%02d\n", hour, min);
	return 0;
}