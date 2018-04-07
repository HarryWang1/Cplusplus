/*
Justin Lin
NYU ID: jwl488
N#: 19699912
Name File: Rec11
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

class Parent {
public:
	virtual void whereami() const{
		cout << "Parent" << endl;
	}
};
class Child : public Parent {
public:
	virtual void whereami() const {
		cout << "Child!!" << endl;
	}
};

/*
Prototype Main Function
*/
void func(Parent& base) { cout << "func(Parent)\n"; }
void func(Child& derived) { cout << "func(Child)\n"; }

void otherFunc(Parent& base) {
	func(base);
	base.whereami();
}
/*
Main Function
*/
int main() {
	Child child;
	//func(child) <-- call right one, func(Child)
	otherFunc(child); //<-- Call parent function, b/c otherFunc only knows it by Parent when it passes into Func. But poly if it does base.whereami();
}

/*/
Functions
*/
