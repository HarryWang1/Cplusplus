//#include <iostream>
//using namespace std;
//class Base {
//public:
//	void bar() const { //HAHA not marked virtual
//		cout << "In Base::bar()\n";
//	}
//private:
//};
//
//class Derived : public Base {
//public:
//	void bar() const {
//		cout << "In Derived::bar()\n";
//	}
//};
//
//void foo(Base &b) {
//	cout << "In foo(Base)";
//	b.bar(); //How to get this to say Derived::bar()
//}
//
//void foo(Derived& d) {
//	cout << "In foo(Derived)\n";
//}
//
//void first(Base& b) {
//	foo(b);
//}
//
//int main() {
//	Derived d;
//	first(d);
//}
//
///*
//1) What will main do?
//2) How to get b.bar() to be called as Derived
//3) Difference between passing in as param and calling as method if virtual.
//*/