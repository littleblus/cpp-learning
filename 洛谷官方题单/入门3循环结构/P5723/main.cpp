#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int L;
	scanf("%d", &L);
	if (L < 2)
		printf("0\n");
	else if (L == 2)
		printf("2\n1\n");
	else {
		int weight = 2;//������������,����������2
		int count = 1;//�����е���������������������2
		//������
		int i = 3;
		printf("2\n");
		while (1) {
			bool prime = true;
			int flag = 0;//��������
			for (int j = 1; j <= i; j++) {
				if (i % j == 0)
					flag++;
				if (flag > 2) {
					prime = false;
					break;
				}
			}
			if (prime == true) {
				if (L - weight < i)
					break;
				printf("%d\n", i);
				count++;
				weight += i;
			}
			i += 2;//i����
		}
		printf("%d\n", count);
	}
	return 0;
}