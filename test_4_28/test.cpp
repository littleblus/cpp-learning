#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"Date.h"

using namespace std;

int main() {
	Date d1(2021, 11, 22);
	Date d2(2023, 4, 28);
	cout << d2 - d1 << endl;
	d1.print();
	d1 = d2 += 3;
	d1.print();
	
	return 0;
}