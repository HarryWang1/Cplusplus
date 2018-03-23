/*
Justin Lin
NYU ID: jwl488
N#: 19699912
Name File: rec9_Overloading
Purpose: 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/*
Classes and Structs
*/
class Complex {
	friend ostream& operator<<(ostream& os, const Complex& rhs) {
		os << rhs.real;
		if (rhs.imaginary >= 0) os << '+';
		os << rhs.imaginary << 'i';
		return os;
	}

public: 
	Complex() : real(0), imaginary(0) {}
	Complex(double real) : real(real), imaginary(0) {}
	Complex(double real, double imag) : real(real), imaginary(imag) {}

	Complex& operator+=(const Complex& rhs) {
		real += rhs.real;
		imaginary += rhs.imaginary; 
		return *this;
	}

	Complex& operator++() {
		++real;
		return *this;
	}

	Complex& operator++(int) {//just putting the type is basically putting a dummy parameter. 
		++real;
		return *this;
	}
private:
	double real, imaginary;

};

Complex& operator+(const Complex& lhs, const Complex& rhs) {
	Complex result(lhs);
	result += rhs;
	return result;
}


/*
Prototype Main Function
*/

/*
Main Function
*/
int main() {
	Complex c1; // 0 + 0i
	Complex c2(17);// 17 + 0i
	Complex c3(3, -5);// 3 - 5i
	cout << "c1: " << c1 << endl
		<< "c2: " << c2 << endl
		<< "c3: " << c3 << endl;
	// c1 = c2 + c3;
	// c1 += c2;
	c1 + 5; // This will actually work b/c C++ will force 5 to be a complex number, b/c c++
			//Tries to make you happy. 
			// operator+(c1, Complex(5)); << this is what the compiler did to try to make me happy.
	5 + c1; // This will also work.
	//Implicit conversion

	++c1;
	c1.operator++();


	c1++;; //Overloading below
	c1.operator++(0);

	ifstream ifs("somefile");
	string word;
	while(ifs>>word){}

}


/*/
Functions
*/
