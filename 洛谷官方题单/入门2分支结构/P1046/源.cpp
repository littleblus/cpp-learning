#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n[10];
	int height;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &n[i]);
	}
	scanf("%d", &height);
	height += 30;
	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (n[i] <= height)
			count++;
	}
	printf("%d\n", count);
	return 0;
}