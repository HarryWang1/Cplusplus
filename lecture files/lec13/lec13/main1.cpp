#include <iostream>
#include <vector>
#include <cstdlib>

#include <exception>
#include <stdexcept>

#define NDEBUG //This will toggle assert
#include <cassert>

using namespace std;

struct OurException : public exception {
	OurException(int n) : n(n) {}
	int n;
};

void bar(int n) {
	assert(n <= 200); //Forces n to be less; if it is greater will crash the program

	if (n > 200) {
		throw OurException(n);
	}
}

void foo(int n) { bar(n); }

int main() {
	try {
		foo(300);
	}
	catch (OurException& ex) {
		cout << "Caught OurException\n" << endl;

	}
	catch (...) {
		cerr << "Caught something but I have no idea what .\n" << endl;
		cerr << "So long and thanks for all the fish\n";
	}

}
