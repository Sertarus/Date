#include "Date.hpp"
#include <list>
#include <iostream>

using namespace std;

Date::Date(int year, int month, int day) {
	if (isValidDate(year, month, day)) {
		this->year = year;
		this->month = month;
		this->day = day;
	}
	else cout << "Incorrect date";
}

Date::~Date() {

}

void Date::SetDate(int year, int month, int day) {
	if (isValidDate(year, month, day)) {
		this->year = year;
		this->month = month;
		this->day = day;
	}
	else throw std::invalid_argument("Incorrect date");
}

Date& Date::operator++() {
	if (isValidDate(this->year, this->month, this->day + 1)) {
		this->day++;
		return *this;
	}
	else if (isValidDate(this->year, this->month + 1, 1)) {
		this->day = 1;
		this->month++;
		return *this;
	}
	else {
		this->day = 1;
		this->month = 1;
		this->year++;
		return *this;
	}
}

Date& Date::operator--() {
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0) {
		days[1] = 28;
	}
	if (isValidDate(this->year, this->month, this->day - 1)) {
		this->day--;
		return *this;
	}
	else if (isValidDate(this->year, this->month - 1, days[month - 2])) {
		this->day = days[month - 2];
		this->month--;
		return *this;
	}
	else {
		this->day = days[11];
		this->month = 12;
		this->year--;
		return *this;
	}
}

Date Date::operator++(int) {
	Date temp(year, month, day);
	++(*this);
	return temp;
}

Date Date::operator--(int) {
	Date temp(year, month, day);
	--(*this);
	return temp;
}

std::ostream& operator<< (std::ostream& out, const Date& date) {
	out << date.day << "." << date.month << "." << date.year << endl;
	return out;
}

std::istream& operator>> (std::istream& in, Date& date) {
	in >> date.day;
	in >> date.month;
	in >> date.year;
	return in;
}

 bool Date::isValidDate(int year, int month, int day) {
	if (month < 1 || month > 12) {
		return false;
	}
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0) {
		days[1] = 28;
	}
	if (day < 1 || day > days[month - 1]) {
		return false;
	}
}