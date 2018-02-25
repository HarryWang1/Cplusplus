/*
Justin Lin
NYU ID: jwl488
N#: 19699912
Name File: TutoringPractice
Purpose: To sort and maintain the names of chemical formulas along with their structure and makeup.
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

class Person {
public:
	Person(const string& theName) : name(theName), spouse(nullptr) {}

	bool has() {
		bool returnV = false;
		if (!children.empty()) {
			returnV = true;
		}
		if (spouse != nullptr && !spouse->children.empty()) {
			returnV = true;
		}
		return returnV;
	}

	bool divorces() {
		if (spouse != nullptr) {
			spouse = nullptr;
			spouse->spouse = nullptr;
			return true;
		}
		return false;
	}

	bool marries(Person& theSpouse) {
		if (spouse == nullptr) {
			spouse = &theSpouse;
			theSpouse.spouse = this;
			return true;
		}
		return false;

	}

private:
	string name;
	Person* spouse;
	vector <Person*> children;
};

/*
Prototype Main Function
*/

/*
Main Function
*/
int main() {

}

/*/
Functions
*/
