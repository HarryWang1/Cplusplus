/*
Justin Lin
Name File:
Purpose:

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*
Structs
*/
class Person {
public:
	Person(const string& theName) : name(theName){ // Better way to initialize. This is called an initialization list.
		//name = theName;// sloppy way to write this. 
		/*
		This is b/c the string name has already been initialized, and then ur setting name to thename, wasting nanoseconds.
		*/
	}

	void setName(const string& theName) {name = theName;}
	string getName() {
		return name;
	}
	
private:
	string name;
		
};

/*
Prototype Main Function

*/
void displayPerson(const Person& aPerson);

/*
Main Function
*/
int main() {
	Person john("John");
	//john.name = "John";
	displayPerson(john);
}

/*/
Functions
*/

void displayPerson(const Person& aPerson) {
	cout << "Person: " << aPerson.name() << endl;
}