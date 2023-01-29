#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int input = 0;
	scanf("%d", &input);
	int p1 = 0, p2 = 0;
	if (input % 2 == 0)
		p1 = 1;
	if (input > 4 && input <= 12)
		p2 = 1;
	int o1 = 0, o2 = 0, o3 = 0, o4 = 0;
	if (p1 && p2)
		o1 = 1;
	if (p1 || p2)
		o2 = 1;
	if ((p1 == 1 && p2 == 0) || (p1 == 0 && p2 == 1))
		o3 = 1;
	if (!p1 && !p2)
		o4 = 1;
	printf("%d %d %d %d\n", o1, o2, o3, o4);
	return 0;
}