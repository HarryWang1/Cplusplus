/*
Justin Lin
NYU ID: jwl488
N#: 19699912
Name File: lec7
Copy constructor, assignment operator, and deconstructor.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Thing {
	friend ostream& operator<<(ostream& os, const Thing& rhs) {
		//return os << "Thing: " << *rhs.p;
		//can also do...
		os << "Thing: " << *rhs.p;
		return os;
	}

public:
	Thing(int x) { p = new int(x); }

	Thing(const Thing& anotherThing) {
		p = new int(*anotherThing.p);
	}

	void setValue(int val) { *p = val; }
	~Thing() {
		delete p; //destructor
	}

	Thing& operator=(const Thing& rhs) {
		/*
		1. Free up whatever heap space the lhs is holding (destructor)
		2. Copy constructor code
		2. a. allocate
		2. b. copying
		*/
		if (this != &rhs) {
			//Free up whatever heap the lhs is holding
			delete p;
			//copying
			p = new int(*rhs.p);
		}
		return *this;
	}

private:
	int* p;
};

void doNothing(Thing x) {}

void simpleFunc() {
	Thing aThing(17);
	doNothing(aThing);
	cout << aThing << endl;

	Thing something(6);

	aThing = something;
	aThing.operator=(something);
	//Will cause a memory leak b/c after this function is finished, you lose the pointer to the int.
	//aThing.cleanup();
}

int main() {
	simpleFunc();
	Thing* ptr = new Thing(100);
	delete ptr;
}