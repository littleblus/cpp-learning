#pragma once

#include<iostream>

class Date {
public:
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month);
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
	}
	// ��ӡ
	void print() {
		std::cout << _year << "-" << _month << "-" << _day << std::endl;
	}
	// �������캯��
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	// ��ֵ����
	Date& operator=(const Date& d);
	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day);
	// ����-=����
	Date& operator-=(int day);
	// ����-����
	Date operator-(int day);
	// ǰ��++
	Date& operator++();
	// ����++
	Date operator++(int);
	// ǰ��--
	Date& operator--();
	// ����--
	Date operator--(int);
	// >���������
	bool operator>(const Date& d);
	// ==���������
	bool operator==(const Date& d);
	// >=���������
	bool operator>=(const Date& d);
	// <���������
	bool operator<(const Date& d);
	// <=���������
	bool operator<=(const Date& d);
	// !=���������
	bool operator!=(const Date& d);
	// ����-���� ��������
	int operator-(const Date& d);
	//����
	int countDays(int year, int month, int day);
private:
	int _year;
	int _month;
	int _day;
};