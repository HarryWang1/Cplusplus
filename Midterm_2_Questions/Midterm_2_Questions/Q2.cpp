//#include <iostream>
//using namespace std;
//class Thing {
//public:
//	Thing() { cout << "1"; }
//	~Thing() { cout << "2"; }
//private:
//
//};
//
//
//class Parent {
//public:
//	Parent() { cout << "3"; }
//	~Parent() { cout << "4"; }
//private:
//
//};
//
//class child : private Parent {
//public:
//	child() { cout << "5"; }
//	~child() { cout << "6"; }
//private:
//	Thing meme;
//};
//
//class GrandChild :protected child {
//public:
//	GrandChild() { cout << "7"; }
//	~GrandChild() { cout << "8"; }
//};
//
//int main() {
//	GrandChild g;
//}
//
///*
//What happens when you call main?
//
//Answer: 
//
//3 1 5 7 8 6 2 4
//
//Note 1:
//When initializing you would start from the bottom to the top; and then when you initialize
//with a variable in private, the variable initializes first then the class itself. (Which is why we have
//init lists)
//
//And when you deconstruct, the class deconstructs first than the variable. 
//
//*/   