#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>

//30�֣�TLE
int main() {
	int n, m;
	int Square = 0;
	int Rectangle = 0;
	scanf("%d%d", &n, &m);
	//�������������ж� ax,ay;bx.by
	for (int bx = 1; bx <= n; bx++) {
		for (int by = 1; by <= m; by++) {
			for (int ax = 1; ax <= bx; ax++) {
				for (int ay = 1; ay <= by; ay++) {
					if (bx - ax == by - ay)
						Square++;
					else
						Rectangle++;
				}
			}
		}
	}
	printf("%d %d\n", Square, Rectangle);
	return 0;
}