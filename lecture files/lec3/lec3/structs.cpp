/*
lec03
Justin Lin
Learning Structs
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Person {
	string name; //Defined as an empty string if nothing in it
	int age; // Won't know b/c initialized to the memory address
};

int main() {
	Person someone;
	string s;
	int x;

	someone.name = "Fred";
	someone.age = 17;

	Person someoneElse;

	// == Won't work, b/c == doesn't know what to do with different object types. 
	/*
	if (someone == someoneElse) {
		cout << someone << endl;
	}
	*/

	//Assignment will copy over all the field from the object to this new thing. 
	//So all the variables in object Person, for someone, will be copied over to someoneElse.

	someoneElse = someone;

	ifstream personStream("people.txt");
	if (!personStream) {
		cerr << "Unable to open file";
		exit(1);   // call system to stop
	}

	vector<Person> vp;
	string name;
	int age;
	while (personStream >> name >> age) {
		Person anotherPerson;
		anotherPerson.name = name;
		anotherPerson.age = age;
		vp.push_back(anotherPerson);
	}

	for (const Person& aPerson : vp) {
		cout << aPerson.name << '\t' << aPerson.age << endl;
	}
}