/*
Justin Lin
Name File:
Purpose: lec4 and lec5
Classes/structs/data hiding/encapsulation/Overloading Operators
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Person {
public:
	Person(const string& name) : name(name) {}
	void display(ostream& os = cout) const {
		os << "Name: " << name << endl;
	}

private:
	string name;
	//Person& spouse;
	Person* spouse;
};

int main2() {
	Person john("John");
	Person mary("Mary");
	john.display();
	mary.display();

	int x = 17;
	cout << &x << endl; //Address of operator.
	int* p = &x;
	//int *p = &x;

	cout << p << endl;
	cout << *p << endl;
	//john.marries(mary);
}