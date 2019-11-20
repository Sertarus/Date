#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
public:
	Date(int year, int month, int day);

	~Date();

	void SetDate(int year, int month, int day);

	Date& operator++();

	Date& operator--();

	Date operator++(int);

	Date operator--(int);

	friend std::ostream& operator<< (std::ostream& out, const Date& date);

	friend std::istream& operator>> (std::istream& in, Date& date);


private:
	int year;
	int month;
	int day;

	static bool isValidDate(int year, int month, int day);
};

#endif 
