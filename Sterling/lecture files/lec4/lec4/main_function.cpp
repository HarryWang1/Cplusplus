/*
Justin Lin
Name File:
Purpose: lec4 / lec5 / lec6
Classes/structs/data hiding/encapsulation/Overloading Operators
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
	friend ostream& operator<<(ostream& os, const Person& somebody); //You can put a prototype or define it entirely here using the friend function
	class Date {
	public:
		Date(int m, int d, int y) : month(m), day(d), year(y) {}
		//Primitive data types are not initialized. So you don't need to create an initialization list. 
		//Could also just put it in the body.

		void display() const {
			cout << month << '/' << day << '/' << year;

		}
		int month, day, year; // <-- if these are const, then you need to use the initialized list, b/c once it is initialized it can't be changed.
	};

public:
	Person(const string& theName, int m, int d, int y) :
		name(theName), dob(m, d, y) { // Better way to initialize. This is called an initialization list.
		//name = theName;// sloppy way to write this. 
		/*
		This is b/c the string name has already been initialized, and then ur setting name to thename, wasting nanoseconds.
		*/
		// The dob(m, d, y) is constructing based on the date class. 
	}

	void setName(const string& theName) { name = theName; }

	void display() const {
		cout << "Person : " << name << endl;
		cout << "Person: name = " << name << ", dob = ";
		dob.display();
		cout << endl;
	}


private:
	string name;
	Date dob; //This is how it knows that it was a date class. 

};

/*
Prototype Main Function

*/
void displayPerson(const Person& aPerson);

/*
Comment Section:
*//*
	cout << john;
	operator<< (cout, john);
	ostream& operator << (ostream& os, const Person& somebody){
		return os;
	}

	Opening osStream by reference, and then returning that os.
*/


//Overloading Operator
ostream& operator << (ostream& os, const Person& somebody) {
	os << "Person: " << somebody.name  + "yo"<< endl;
	return os;
}

/*
Main Function
*/
int main() {
	Person john("John", 1, 1, 1999);
	//john.name = "John";
	john.display();

	cout << john;
	operator<< (cout, john);
	

	string s;
	s = "Felix";
	string s2 = "Felix";
}

/*/
Functions
*/

void displayPerson(const Person& aPerson) {
	//aPerson.display();
	/*
		The code above wouldn't be able to run though, b/c it it is a const. And it doesn't know whether or not,
		display would have changed the object or not, and thus wouldn't run unless the method was named as const.

		this the method would need to be void display const(), so that the method is now a const.
	*/
	aPerson.display();
}