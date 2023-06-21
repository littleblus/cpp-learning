#pragma once

#include<iostream>

class Date {
	// ��Ԫ�������������ܷ������Ʒ�Ӱ��
	friend std::ostream& operator<<(std::ostream& out, const Date& d);
	friend std::istream& operator>>(std::istream& in, Date& d);
public:
	// ��ȡĳ��ĳ�µ�����
	static int GetMonthDay(int year, int month);
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1) {
		if (month > 0 && month < 13 && day > 0 && day < GetMonthDay(year, month)) {
			_year = year;
			_month = month;
			_day = day;
		}
		else {
			std::cout << "�Ƿ�����" << std::endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}
	// ��ӡ
	void print()const {
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
	bool operator>(const Date& d)const;
	// ==���������
	bool operator==(const Date& d)const;
	// >=���������
	bool operator>=(const Date& d)const;
	// <���������
	bool operator<(const Date& d)const;
	// <=���������
	bool operator<=(const Date& d)const;
	// !=���������
	bool operator!=(const Date& d)const;
	// ����-���� ��������
	int operator-(const Date& d)const;
	//����
	int countDays(int year, int month, int day)const;
private:
	int _year;
	int _month;
	int _day;
};