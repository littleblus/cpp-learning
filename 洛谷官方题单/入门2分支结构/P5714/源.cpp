#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

int main() {
	double m, h;
	cin >> m >> h;
	double bmi = m / (h * h);
	if (bmi < 18.5) {
		cout << "Underweight" << endl;
	}
	else if (bmi >= 18.5 && bmi < 24) {
		cout << "Normal" << endl;
	}
	else {
		cout << bmi << endl << "Overweight" << endl;
	}
	return 0;
}