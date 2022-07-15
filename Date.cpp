#include "Date.h"

Date::Date()
{
	day = {};
	month = {};
	year = {};
}

Date::Date(const int& day, const int& month, const int& year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

void Date::setDay(const int& day)
{
	if (day >= 1 && day <= 31)
	{
		this->day = day;
	}
	else
	{
		this->day = {};
	}
}

int Date::getDay() const
{
	return this->day;
}

void Date::setMonth(const int& month)
{
	if (month >= 1 && month <= 12)
	{
		this->month = month;
	}
	else
	{
		this->month = {};
	}
}

int Date::getMonth() const
{
	return this->month;
}

void Date::setYear(const int& year)
{
	if (year >= 1900 && year <= 3000)
	{
		this->year = year;
	}
	else
	{
		this->year = {};
	}
}

int Date::getYear() const
{
	return this->year;
}

void Date::display() const
{
	cout << this->day << " / " << this->month << " / " << this->year << endl;
}
