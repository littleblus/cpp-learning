#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <climits>

int main() {
	int Numcount;
	scanf("%d", &Numcount);
	int min = INT_MAX;
	int max = INT_MIN;
	for (int i = 0; i < Numcount; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp < min)
			min = tmp;
		if (tmp > max)
			max = tmp;
	}
	printf("%d\n", max - min);
	return 0;
}