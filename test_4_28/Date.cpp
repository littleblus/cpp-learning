#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int Date::GetMonthDay(int year, int month) {
	static int daysArr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && isLeapYear(year))
		return 29;
	else
		return daysArr[month - 1];
}

Date& Date::operator=(const Date& d) {
	if (this != &d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

Date& Date::operator+=(int day) {
	if (day < 0)
		return *this -= day;
	_day += day;
	while (_day > GetMonthDay(_year, _month)) {
		_day -= GetMonthDay(_year, _month);
		if (_month < 12)
			++_month;
		else {
			++_year;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day) {
	Date tmp = *this;
	tmp += day;
	return tmp;
}

Date& Date::operator-=(int day) {
	if (day < 0)
		return *this += -day;
	_day -= day;
	while (_day < 1) {
		if (_month > 1) {
			--_month;
			_day += GetMonthDay(_year, _month);
		}
		else {
			--_year;
			_month = 12;
			_day += 31;
		}
	}
	return *this;
}

Date Date::operator-(int day) {
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

Date& Date::operator++() {
	*this += 1;
	return *this;
}

Date Date::operator++(int) {
	Date tmp = *this;
	*this += 1;
	return tmp;
}

Date& Date::operator--() {
	*this -= 1;
	return *this;
}

Date Date::operator--(int) {
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

bool Date::operator>(const Date& d)const {
	if (_year < d._year)
		return false;
	else if (_year == d._year && _month < d._month)
		return false;
	else if (_year == d._year &&
		_month == d._month && _day <= d._day)
		return false;
	return true;
}

bool Date::operator==(const Date& d)const {
	if (_day == d._day && _month == d._month && _year == d._year)
		return true;
	else
		return false;
}

bool Date::operator>=(const Date& d)const {
	return *this > d || *this == d;
}

bool Date::operator<(const Date& d)const {
	return !(*this >= d);
}

bool Date::operator<=(const Date& d)const {
	return *this < d || *this == d;
}

bool Date::operator!=(const Date& d)const {
	return !(*this == d);
}

int Date::operator-(const Date& d)const {
	int days1 = countDays(_year, _month, _day);
	int days2 = countDays(d._year, d._month, d._day);
	return days1 - days2;
}

int Date::countDays(int year, int month, int day)const {
	int days = day;
	for (int y = 1; y < year; ++y) {
		days += isLeapYear(y) ? 366 : 365;
	}
	for (int m = 1; m < month; ++m) {
		days += GetMonthDay(year, m);
	}
	return days;
}

//全局函数没有this指针
std::ostream& operator<<(std::ostream& out, const Date& d) {
	out << d._year << "年" << d._month << "月" << d._day << "日";
	return out;
}

std::istream& operator>>(std::istream& in, Date& d) {
	int y, m, day;
	in >> y >> m >> day;
	if (m > 0 && m < 13 && d>0 && day > 0 && day < Date::GetMonthDay(y, m)) {
		d._year = y;
		d._month = m;
		d._day = day;
	}
	else {
		std::cout << "非法日期" << std::endl;
	}
	return in;
}