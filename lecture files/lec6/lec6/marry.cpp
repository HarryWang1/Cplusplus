/*
Justin Lin
Name File:
Purpose: lec 6   
Classes/structs/data hiding/encapsulation/Overloading Operators
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Person {
	friend ostream& operator<<(ostream& os, const Person& somebody);
public:
	Person(const string& name) : name(name), spouse(nullptr){}
	void display(ostream& os = cout) const {
		os << "Name: " << name << endl;
		if (spouse == nullptr) {
			os << "Single\n";
		}
		else {
			os << "Married \n";
		}
		os << (spouse == nullptr ? "Single" : " Married" ) << endl;
		if (spouse != nullptr) {
			//os <<  (*spouse).name << endl;
			os << spouse->name << endl;//From pointer go to the name
		}
	}

	bool marries(Person& betrothed) {
		if (spouse == nullptr && betrothed.spouse == nullptr ) {
			//!spouse && !betrothed.spouse
			spouse = &betrothed;
			betrothed.spouse = this;
			return true;
		}
		return false;	
	}

private:
	string name;
	//Person& spouse;
	Person* spouse;
};

ostream& operator << (ostream& os, const Person& somebody) {
	os << "Person: " << somebody.name << endl;
	return os;
}

void dumbFunc() {
	int* p = new int(17);
	delete p;
	cout << *p << endl;

}
int main() {
	Person john("John");
	Person mary("Mary");
	cout << john << endl;
	cout << mary << endl;

	//int* p = new int(17);
	dumbFunc();

	vector <Person*> vp;
	//vp.push_back(&john);
	//vp.push_back(&mary);

	//Creating new person on the heap and store
	vp.push_back(new Person("fred"));

	/*
		Could also do:
		Person* pptr = new Person("sally");
		vp.push_back(pptr);
	*/
}