#pragma once

#include<iostream>

class Date {
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month);
	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
	}
	// 打印
	void print() {
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
	bool operator>(const Date& d);
	// ==运算符重载
	bool operator==(const Date& d);
	// >=运算符重载
	bool operator>=(const Date& d);
	// <运算符重载
	bool operator<(const Date& d);
	// <=运算符重载
	bool operator<=(const Date& d);
	// !=运算符重载
	bool operator!=(const Date& d);
	// 日期-日期 返回天数
	int operator-(const Date& d);
	//天数
	int countDays(int year, int month, int day);
private:
	int _year;
	int _month;
	int _day;
};