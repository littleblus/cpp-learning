#include<iostream>

using namespace std;

//nowcoder - KY258
int GetMonthDay(const int y, const int m) {
	static int days[13]{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (m == 2)
		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
			return 29;
		else
			return 28;
	else
		return days[m];
}

int main() {
	int n;
	cin >> n;
	while (--n >= 0) {
		int y, m, d, a;
		cin >> y >> m >> d >> a;
		d += a;
		while (d > (a = GetMonthDay(y, m))) {
			d -= a;
			m++;
			if (m == 13) {
				y++;
				m = 1;
			}
		}
		printf("%04d-%02d-%02d\n", y, m, d);
	}
	return 0;
}