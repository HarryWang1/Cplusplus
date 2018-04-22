//#include <iostream> 
//using namespace std;
//
//class Base {};
//
//ostream& operator<<(ostream& os, const Base& rhs) {
//	os << "Base";
//	return os;
//}
//
//class Derived : public Base {};
//
//ostream& operator<<(ostream& os, const Derived& rhs) {
//	os << "Derived";
//	return os;
//}
//
//void func(const Base& base) {
//	cout << base << endl;
//	//operator<< (cout, base);
//}
//
//int main() {
//	Derived der;
//	cout << der << endl; //Cannot make output operator virtual, virtuals are only methods.
//	func(der);
//}

//
//#include <iostream> 
//using namespace std;
//
//class Base {
//public:
//	virtual void display(ostream& os) const {
//		os << "Base";
//	}
//};
//
//ostream& operator<<(ostream& os, const Base& rhs) {
//	rhs.display(os);
//	return os;
//}
//class Derived : public Base {
//public:
//	void display(ostream& os) const override {
//		os << "Derived";
//	}
//};
//
//void func(const Base& base) {
//	cout << base << endl;
//}
//
//int main() {
//	Derived der;
//	cout << der << endl; //Cannot make output operator virtual, virtuals are only methods.
//	func(der);
//}


#include <iostream> 
using namespace std;

class Base {
public:
	void foo(int n) const{
		cout << "Base::foo(n)\n";
	}
};

class Derived : public Base {
public:
	using Base::foo; //Tells the compiler that any version of foo, bring them to be avaliable to use.
	void foo() const { cout << "Derived:: foo()\n"; }
	//void foo(int n) const { Base::foo(n); }
};

int main() {
	Derived der;
	der.foo(17);
}

class Justin {
	Justin(string mood) : mood(mood) {
		cout << "Mood: " << mood;
	}
private:
	string mood;
};

int main() {
	Justin("Need Vodka")
}