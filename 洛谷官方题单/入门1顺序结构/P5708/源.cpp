#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <cmath>

int main() {
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	double p = 0.5 * (a + b + c);
	printf("%.1f\n", sqrt(p * (p - a) * (p - b) * (p - c)));
	return 0;
}