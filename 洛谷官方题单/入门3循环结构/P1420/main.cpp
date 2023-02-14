#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	int now, back = -1;
	int count = 1;
	int max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &now);
		if (now - back == 1)
			count++;
		else
			count = 1;
		if (count > max)
			max = count;
		back = now;
	}
	printf("%d\n", max);
	return 0;
}