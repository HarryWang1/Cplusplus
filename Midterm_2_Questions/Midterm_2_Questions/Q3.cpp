//#include <iostream> 
//using namespace std;
//class Parent {
//public:
//	virtual void bar() const { cout << "In Parent::bar()"; }
//};
//
//class Child : public Parent {
//public:
//	void bar() const { cout << "In Child :: bar()\n"; }
//};
//
//class Grandchild : public Child {
//public: 
//	void bar() const { cout << "In GrandChild::bar()\n"; }
//};
//
//void foo(Parent &p) {
//	cout << "In foo(parent)\n";
//	p.bar();
//}
//
//void foo(Child& c) {
//	cout << "In foo(child)\n";
//	c.bar();
//}
//
//int main() {
//	Grandchild g;
//	foo(g);
//}
//
///*
//What happens when you call main?
//
//In foo(child)
//in GrandChild:bar();
//
//Thing to note, when you mark virutal in the base, you don't need to mark
//everything virtual. 
//
//When calling foo(g), will go to the Child b/c it has a child and is more specific. 
//
//Ex. All birds are animals, but not all animals are birds. 
//Then you have chicken, which would u say it is? 
//More specific would be bird, and that is what C++ does. 
//*/