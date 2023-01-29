#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int a[3];
	scanf("%d%d%d", &a[0], &a[1], &a[2]);
	sort(a, a + 3);
	if (a[0] + a[1] <= a[2]) {
		printf("Not triangle\n");
	}
	else {
		if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) {
			printf("Right triangle\n");
		}
		else if (a[0] * a[0] + a[1] * a[1] > a[2] * a[2]) {
			printf("Acute triangle\n");
		}
		else {
			printf("Obtuse triangle\n");
		}
		if (a[0] == a[1]) {
			printf("Isosceles triangle\n");
			if (a[0] == a[2])
				printf("Equilateral triangle\n");
		}
	}
	return 0;
}