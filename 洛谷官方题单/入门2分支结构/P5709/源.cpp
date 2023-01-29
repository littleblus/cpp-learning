#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int m, t, s;
	scanf("%d%d%d", &m, &t, &s);
	if (t == 0) {
		printf("0\n");
		return 0;
	}
	if (s % t == 0)
		printf("%d\n", max(m - s / t, 0));
	else
		printf("%d\n", max(m - s / t - 1, 0));
	return 0;
}