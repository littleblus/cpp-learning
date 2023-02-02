#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <climits>

int main() {
	int n;
	scanf("%d", &n);
	int tmp, min = INT_MAX;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp < min) {
			min = tmp;
		}
	}
	printf("%d\n", min);
	return 0;
}