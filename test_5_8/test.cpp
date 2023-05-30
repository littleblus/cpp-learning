#include<iostream>

using namespace std;

//nowcoder - JZ64 
class Solution {
	class add {
	public:
		add() {
			_n += _i;
			_i++;
		}
		static int getn() { return _n; }
	private:
		static int _i;
		static int _n;
	};
public:
	int Sum_Solution(int n) {
		add* tmp = new add[n];
		int sum = add::getn();
		delete[] tmp;
		return sum;
	}
};

int Solution::add::_i = 1;
int Solution::add::_n = 0;



//nowcoder - HJ73
int main() {
	int y, m, d;
	int ret(0);
	cin >> y >> m >> d;
	int days[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		days[1]++;
	for (int i = 0; i < m - 1; ++i) {
		ret += days[i];
	}
	ret += d;
	cout << ret << endl;
	return 0;
}



//nowcoder - KY111
class date {
public:
    date(int y, int m, int d)
        : _year(y)
        , _month(m)
        , _day(d) {
    }

    static int GetMonthDay(const int y, const int m) {
        int days[13]{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            days[2]++;
        }
        return days[m];
    }

    int operator-(const date& x) const {
        int days1(0);
        int days2(0);
        for (int i = 0; i < _year; ++i) {
            if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
                days1 += 366;
            else
                days1 += 365;
        }
        for (int i = 0; i < x._year; ++i) {
            if ((x._year % 4 == 0 && x._year % 100 != 0) || x._year % 400 == 0)
                days2 += 366;
            else
                days2 += 365;
        }
        for (int i = 1; i < _month; ++i) {
            days1 += GetMonthDay(_year, i);
        }
        for (int i = 1; i < x._month; ++i) {
            days2 += GetMonthDay(x._year, i);
        }
        days1 += _day;
        days2 += x._day;
        return days1 - days2 + 1;
    }
private:
    int _year = 1900;
    int _month = 1;
    int _day = 1;
};

int main() {
    int y, m, d;
    scanf("%4d%2d%2d", &y, &m, &d);
    date d1(y, m, d);
    scanf("%4d%2d%2d", &y, &m, &d);
    date d2(y, m, d);
    cout << d2 - d1 << endl;
    return 0;
}



//nowcoder - KY222
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
	int y, d;
	while (cin >> y >> d) {
		int m(1);
		printf("%04d-", y);
		for (int i = 0; i < 12; ++i) {
			d -= GetMonthDay(y, i);
			if (d <= GetMonthDay(y, i + 1))
				break;
			++m;
		}
		printf("%02d-%02d\n", m, d);
	}
	return 0;
}