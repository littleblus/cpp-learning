#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int arr[3];
	scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
	sort(arr, arr + 3);
	//求两个数的最大公约数
	int max = 0;
	for (int i = 1; i <= arr[0]; i++) {
		if (arr[0] % i == 0 && arr[2] % i == 0) {
			max = i;
		}
	}
	printf("%d/%d\n", arr[0] / max, arr[2] / max);
	return 0;
}