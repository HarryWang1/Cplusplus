//#include <iostream>
//using namespace std;
//
//class Animal {
//public:
//	Animal(const string& s) : name(s){
//
//	}
//protected:
//	void changeName(Animal &a, const string &s) {
//		a.name = s;
//	}
//private:
//	string name;
//};
//
//class Dog : public Animal {
//public:
//	Dog(const string& s) : Animal(s) {}
//};
//
//class Cat : public Animal {
//public:
//	Cat(const string& s) : Animal(s) {}
//};
//
//int main() {
//	Dog d("Nika");
//	Cat c("Roman");
//	d.changeName(c, "Jacob");
//}
//
///*
//Protected methods can not be runned outside of the class, only internally within derived class. 
//
//So changeName won't run in main, but would run if you put it inside the Cat or Dog class. 
//*/

///*
//====================================
//Part 2 Variation of the Question
//====================================
//
//*/
//#include <iostream>
//using namespace std;
//
//class Animal {
//public:
//	Animal(const string& s) : name(s) {
//
//	}
//protected:
//	string name;
//};
//
//class Dog : public Animal {
//public:
//	Dog(const string& s) : Animal(s) {}
//
//	void changeName(Animal &a, const string &s) {
//		a.name = s; //<-- Different classes cannot access each other's protected variables
//		//If you changed ANimal &a to Dog& a though then it would work. 
//	}
//};
//
//
//
//class Cat : public Animal {
//public:
//	Cat(const string& s) : Animal(s) {}
//};
//
//int main() {
//	Dog d("Nika");
//	Cat c("Roman");
//	d.changeName(c, "Jacob");
//}
//
