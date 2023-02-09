#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

const double ratio = 0.98;

int main() {
	double meter;
	scanf("%lf", &meter);
	double sum = 0;
	int count = 0;
	double tmpnow = 2;
	while (sum < meter) {
		sum += tmpnow;
		tmpnow *= ratio;
		count++;
	}
	printf("%d\n", count);
	return 0;
}