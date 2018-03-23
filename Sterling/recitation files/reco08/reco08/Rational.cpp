#include "Rational.h"

namespace CS2124 {

	int Rational::greatestCommonDivisor(int x, int y) {
		while (y != 0) {
			int temp = x % y;
			x = y;
			y = temp;
		}
		return x;
	}

	Rational::Rational(int theNum, int theDenom = 1) : num(theNum), denom(theDenom) {
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
		int gcd = greatestCommonDivisor(denom, rhs.denom);
		num *= gcd;
		denom *= gcd;

		int copyRhsNum = rhs.num;
		int copyRhsDenom = rhs.denom;

		copyRhsNum *= gcd;
		copyRhsNum *= gcd;

		num += copyRhsNum;
		denom += copyRhsDenom;

		gcd = greatestCommonDivisor(num, denom);
		num = num / gcd;
		denom = denom / gcd;

		return *this;
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

	// Define prefix decrement operator. 

	int Rational::getNum() const {
		return num;
	}

	int Rational::getDenom() const {
		return denom;
	}

	Rational::operator bool() const
	{
		return num != 0;
	}

	Rational& operator+(const Rational& lhs, const Rational& rhs)
	{
		// TODO: insert return statement here
		Rational result(lhs);
		result += rhs;
		return result;
	}

	bool operator==(const Rational& lhs, const Rational & rhs)
	{
		return false;
	}
	bool operator!=(const Rational& lhs, const Rational & rhs)
	{
		return false;
	}
	Rational& operator--(Rational& rhs)
	{
		// TODO: insert return statement here
		rhs += -1;
		return rhs;
	}
	Rational& operator--(Rational& lhs, int)
	{
		// TODO: insert return statement here
		lhs += -1;
		return lhs;
	}
}