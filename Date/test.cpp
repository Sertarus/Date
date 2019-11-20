#include "Date.hpp"
#include <iostream>

using namespace std;

int main() {
	Date test(1998, 2, 30);
	cout << test;
	test.SetDate(1985, 6, 4);
	cout << test;
	cin >> test;
	test++;
	cout << test;
	test--;
	cout << test;
}