#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace CS2124 {
	class Rational {
		friend istream &operator>>(istream &input, Rational &rhs);
		friend ostream& operator<<(ostream& os, const Rational& rhs);
		friend bool operator==(const Rational& lhs, const Rational& rhs);
		friend bool operator<(const Rational& lhs, const Rational& rhs);
	public:
		Rational::Rational();

		Rational::Rational(int theNum);

		Rational(int theNum, int theDenom);

		Rational& operator+=(const Rational& rhs);

		Rational& operator++();

		Rational& operator++(int);

		explicit operator bool() const;

	private:
		int num, denom;

	};


	Rational operator+(const Rational& lhs, const Rational& rhs);

	bool operator!=(const Rational& lhs, const Rational& rhs);

	Rational& operator--(Rational& rhs);

	Rational& operator--(Rational& lhs, int);

	int greatestCommonDivisor(int x, int y);

	bool operator<=(const Rational& lhs, const Rational& rhs);

	bool operator>(const Rational& lhs, const Rational& rhs);

	bool operator>=(const Rational& lhs, const Rational& rhs);
	

}

#endif
