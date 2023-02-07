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
		int weight = 2;//背包的质数和,算上特例的2
		int count = 1;//背包中的质数个数，算上特例的2
		//求质数
		int i = 3;
		printf("2\n");
		while (1) {
			bool prime = true;
			int flag = 0;//整除个数
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
			i += 2;//i递增
		}
		printf("%d\n", count);
	}
	return 0;
}