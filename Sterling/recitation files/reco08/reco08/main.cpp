/*
Justin Lin
NYU ID: jwl488
N#: 19699912
Name File: reco08
Purpose:
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Classes and Structs
*/

int greatestCommonDivisor(int x, int y) {
	while (y != 0) {
		int temp = x % y;
		x = y;
		y = temp;
	}
	return x;
}

class Rational {
public:
	Rational(int theNum, int theDenom) : num(theNum), denom(theDenom) {
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

	Rational& operator+=(const Rational& rhs) {
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

	Rational& operator++() {
		num += denom;
		int gcd = greatestCommonDivisor(num, denom);

		num = num / gcd;
		denom = denom / gcd;

		return *this;
	}

	Rational& operator++(int) {
		num += denom;
		int gcd = greatestCommonDivisor(num, denom);

		num = num / gcd;
		denom = denom / gcd;

		return *this;
	}

	//Define prefix decrement operator.

		int getNum() const {
		return num;
	}

	int getDenom() const {
		return denom;
	}

	explicit operator bool() const { return num != 0; }

private:
	int num, denom;
};


Rational& operator+(const Rational& lhs, const Rational& rhs) {
	Rational result(lhs);
	result += rhs;
	return result;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
	if (lhs.getNum() == rhs.getNum() && lhs.getDenom() == rhs.getDenom()) {
		return true;
	}
	return false;
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
	if (lhs.getNum() == rhs.getNum() && lhs.getDenom() == rhs.getDenom()) {
		return false;
	}
	return true;
}

Rational& operator--(Rational& rhs) {
	Rational subtract(-1, 1);
	rhs += subtract;
	return rhs;
}

Rational& operator--(Rational& lhs, int) {
	Rational subtract(-1, 1);
	lhs += subtract;
	return lhs;
}
