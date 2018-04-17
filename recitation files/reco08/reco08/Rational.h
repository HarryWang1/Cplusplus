#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace CS2124 {
	class Rational {
		//friend Rational& operator+(const Rational& lhs, const Rational& rhs);
		//friend bool operator==(const Rational& lhs, const Rational& rhs);
		//friend bool operator!=(const Rational& lhs, const Rational& rhs);
		//friend Rational& operator--(Rational& rhs);
		//friend Rational& operator--(Rational& lhs, int);
	public:
		int greatestCommonDivisor(int x, int y);

		Rational(int theNum, int theDenom);

		Rational& operator+=(const Rational& rhs);

		Rational& operator++();

		Rational& operator++(int);

		// Define prefix decrement operator. 

		int getNum() const;

		int getDenom() const;

		explicit operator bool() const;

	private:
		int num, denom;

	};


	Rational& operator+(const Rational& lhs, const Rational& rhs);

	bool operator==(const Rational& lhs, const Rational& rhs);

	bool operator!=(const Rational& lhs, const Rational& rhs);

	Rational& operator--(Rational& rhs);

	Rational& operator--(Rational& lhs, int);

}

#endif
