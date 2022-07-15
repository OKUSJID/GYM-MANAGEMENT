#include <iostream>
using namespace std;

#pragma once
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(const int&, const int&, const int&);
	void setDay(const int&);
	int getDay()const;
	void setMonth(const int&);
	int getMonth()const;
	void setYear(const int&);
	int getYear()const;
	void display()const;
};