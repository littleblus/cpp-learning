#include <cstdio>
#include <cmath>

int main() {
	int n;
	scanf("%d", &n);
	printf("%.2f\n", ((pow((1 + sqrt(5)) / 2, n)) - (pow((1 - sqrt(5)) / 2, n))) / sqrt(5));
	return 0;
}