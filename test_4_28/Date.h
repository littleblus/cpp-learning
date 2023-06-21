#pragma once

#include<iostream>

class Date {
	// 友元函数声明，不受访问限制符影响
	friend std::ostream& operator<<(std::ostream& out, const Date& d);
	friend std::istream& operator>>(std::istream& in, Date& d);
public:
	// 获取某年某月的天数
	static int GetMonthDay(int year, int month);
	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1) {
		if (month > 0 && month < 13 && day > 0 && day < GetMonthDay(year, month)) {
			_year = year;
			_month = month;
			_day = day;
		}
		else {
			std::cout << "非法日期" << std::endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}
	// 打印
	void print()const {
		std::cout << _year << "-" << _month << "-" << _day << std::endl;
	}
	// 拷贝构造函数
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	// 赋值重载
	Date& operator=(const Date& d);
	// 日期+=天数
	Date& operator+=(int day);
	// 日期+天数
	Date operator+(int day);
	// 日期-=天数
	Date& operator-=(int day);
	// 日期-天数
	Date operator-(int day);
	// 前置++
	Date& operator++();
	// 后置++
	Date operator++(int);
	// 前置--
	Date& operator--();
	// 后置--
	Date operator--(int);
	// >运算符重载
	bool operator>(const Date& d)const;
	// ==运算符重载
	bool operator==(const Date& d)const;
	// >=运算符重载
	bool operator>=(const Date& d)const;
	// <运算符重载
	bool operator<(const Date& d)const;
	// <=运算符重载
	bool operator<=(const Date& d)const;
	// !=运算符重载
	bool operator!=(const Date& d)const;
	// 日期-日期 返回天数
	int operator-(const Date& d)const;
	//天数
	int countDays(int year, int month, int day)const;
private:
	int _year;
	int _month;
	int _day;
};