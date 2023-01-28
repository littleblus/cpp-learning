#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

int main() {
	int sh, sm, eh, em;
	scanf("%d%d%d%d", &sh, &sm, &eh, &em);
	int h = eh - sh;
	int m = em - sm;
	if (m < 0) {
		h--;
		m += 60;
	}
	printf("%d %d\n", h, m);
	return 0;
}