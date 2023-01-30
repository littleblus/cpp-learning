#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int arr[3];
	scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
	sort(arr, arr + 3);
	char tmp;
	for (int i = 0; i < 3; i++) {
		cin >> tmp;
		if (tmp == 'A')
			printf("%d ", arr[0]);
		if (tmp == 'B')
			printf("%d ", arr[1]);
		if (tmp == 'C')
			printf("%d ", arr[2]);
	}
	return 0;
}