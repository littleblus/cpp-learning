#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000;
int score[maxn] = { 0 };

int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &score[i]);
	}
	sort(score, score + n);
	double avg = 0;
	for (int i = 1; i < n - 1; i++) {
		avg += score[i];
	}
	avg /= n - 2;
	printf("%.2f\n", avg);
	return 0;
}