#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <cmath>
#include <cstring>

bool isPrime(int x) {
	for (int i = 3; i <= sqrt(x); i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

bool isPalindrome(int x) {
	char num[12];
	sprintf(num, "%d", x);
	char* left = num;
	char* right = strlen(num) + num - 1;
	while (left <= right) {
		if (*left != *right)
			return false;
		left++;
		right--;
	}
	return true;
}

//�����11֮�ⲻ����ż��λ�Ļ�������
//�����ж�ż��λֱ������
int digit(int x) {
	int digit = 1;
	while (x > 9) {
		x /= 10;
		digit++;
	}
	return digit;
}

int main() {
	int a, b;//��Χ,���Ϊ100 000 000
	scanf("%d%d", &a, &b);
	//��a����Ϊ����
	if (a % 2 == 0)
		a++;
	if (b > 9989899)
		b = 9989899;
	for (int i = a; i <= b; i += 2) {
		if (i == 11)
			printf("%d\n", i);
		if (digit(i) % 2 == 0)
			continue;
		else if (isPalindrome(i) == false)
			continue;
		else if (isPrime(i) == true)
			printf("%d\n", i);
	}
	return 0;
}