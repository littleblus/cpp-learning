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
	Date d3(2003, 9, 19);
	Date d4 = d3;
	if (d4 >= d3)
		cout << ">=" << endl;
	if (d4 <= d3)
		cout << "<=" << endl;
	d3++;
	if (d4 > d3)
		cout << ">" << endl;
	d4 += 365;
	if (d4 > d3)
		cout << ">" << endl;
	
	return 0;
}