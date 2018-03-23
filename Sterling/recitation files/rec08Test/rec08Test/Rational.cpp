#include "Rational.h"

namespace CS2124 {

	Rational::Rational() : num(0), denom(1) {
	}

	Rational::Rational(int theNum) : num(theNum), denom(1){

	}

	Rational::Rational(int theNum, int theDenom) : num(theNum), denom(theDenom) {
		int gcd = greatestCommonDivisor(num, denom);
		num = num / gcd;
		denom = denom / gcd;

		if (num < 0 || denom < 0) {//Checking if any are less than
			if (num < 0 && denom < 0) {//Checking if both numbers are under then turn abs. 
				num = abs(num);
				denom = abs(denom);
			}

			if (denom < 0 && num > 0) {//If Denom is under move the negative to the top.
				denom = abs(denom);
				num *= -1;
			}
		}
	}

	Rational& Rational::operator+=(const Rational& rhs) {

		//1/3 + 2/4
		//4 / 12 + 6 / 12 = 1.25

		int copyRhsNum = rhs.num;
		int copyRhsDenom = rhs.denom;

		int multiply = denom;

		num *= rhs.denom;
		denom *= rhs.denom;

		copyRhsNum *= multiply;
		copyRhsDenom *= multiply;

		num += copyRhsNum;

		int gcd = greatestCommonDivisor(num, denom);
		num = num / gcd;
		denom = denom / gcd;

		return *this;
	}

	bool operator<(const Rational& lhs, const Rational& rhs) {
		int copyRhsNum = rhs.num;
		int copyLhsNum = lhs.num;

		copyLhsNum *= rhs.denom;
		copyRhsNum *= lhs.denom;

		return (copyLhsNum < copyRhsNum);
	}

	bool operator<=(const Rational& lhs, const Rational& rhs) {
		return (lhs < rhs || (rhs == lhs))
	}

	bool operator>(const Rational& lhs, const Rational& rhs) {
		return ((rhs < lhs) && (lhs != lhs));
	}

	bool operator>=(const Rational& lhs, const Rational& rhs) {
		return ((rhs < lhs) || (lhs == rhs));
	}

	Rational& Rational::operator++() {
		num += denom;
		int gcd = greatestCommonDivisor(num, denom);

		num = num / gcd;
		denom = denom / gcd;

		return *this;
	}

	Rational& Rational::operator++(int) {
		num += denom;
		int gcd = greatestCommonDivisor(num, denom);

		num = num / gcd;
		denom = denom / gcd;

		return *this;
	}

	int greatestCommonDivisor(int x, int y) {
		while (y != 0) {
			int temp = x % y;
			x = y;
			y = temp;
		}
		return x;
	}

	// Define prefix decrement operator. 
	Rational::operator bool() const
	{
		return num != 0;
	}

	Rational operator+(const Rational& lhs, const Rational& rhs)
	{
		// TODO: insert return statement here
		Rational result(lhs);
		result += rhs;
		return result;
	}

	bool operator==(const Rational& lhs, const Rational & rhs)
	{
		if (lhs.num == rhs.num && lhs.denom == rhs.denom) {
			return true;
		}
		return false;
	}
	bool operator!=(const Rational& lhs, const Rational & rhs)
	{
		if (lhs == rhs) {
			return false;
		}
		return true;
	}
	Rational& operator--(Rational& rhs)
	{
		// TODO: insert return statement here
		rhs += Rational(-1);
		return rhs;
	}
	Rational& operator--(Rational& lhs, int)
	{
		// TODO: insert return statement here
		lhs += Rational(-1);
		return lhs;
	}

	istream &operator>>(istream &input, Rational &rhs) {
		int theNum, theDenom;
		char division;
		input >> theNum >> division >> theDenom;
		rhs.num = theNum;
		rhs.denom = theDenom;
		return input;
	}

	ostream & operator<<(ostream & os, const Rational & rhs)
	{
		os << rhs.num << "/" << rhs.denom;
		return os;
	}
}