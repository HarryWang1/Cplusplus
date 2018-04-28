/*
Justin Lin
NYU ID: jwl488
N#: 19699912
Name File: lec11
Purpose:
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <array>
#include <utility>
using namespace std;


//char* myFind(char* start, char* stop, char target) {
//	for (char* p = start; start != stop; ++p) {
//		if (*p == target)
//			return p;
//	}
//	return stop;
//}

list<char>::iterator myFind(list<char>::iterator start,
	list<char>::iterator stop, char target) {
	for (list<char>::iterator p = start; start != stop; ++p) {
		if (*p == target)
			return p;
	}
	return stop;
}

template <typename T, typename U>
T myFind(T start, T stop, U predicate) { //predicate, just a normal variable name, but helpful naming to say that it is either true or false. 
	for (T p = start; p != stop; ++p) {
		if (*p == predicate) {//treating the predicate like a function, b/c passing in name of function, or functor, or lambda
			return p;
		}
	}
	return stop;
}

//template <typename T, typename U>
//T myFind(T start, T stop, U predicate) { //predicate, just a normal variable name, but helpful naming to say that it is either true or false. 
//	for (T p = start; p != stop; ++p) {
//		if (predicate(*p)) {//treating the predicate like a function, b/c passing in name of function, or functor, or lambda
//			return p;
//		}
//	}
//	return stop;
//}

bool isOdd(int n) { return n % 2 != 0; }

struct isEven {
	//overloading the parenthesis
	bool operator() (int n) { return n % 2 == 0; }
};

struct isMultiple {
	//overloading the parenthesis
	isMultiple(int n) : divisor(n) {}
	bool operator() (int n) { return n % divisor == 0; }
	int divisor;
};

//void foo(auto x) { cout << x << endl; } // <-- can't do this b/c it doesn't know what it is doing... auto
//doesn't change the static typing, or that u need to specify type. Template is something else, it makes you specify
//a type. it makes a new copy of a function replacing the templates, T, with the now staticallyl typed type. 

//You can do something like...
auto foo() { return 17; } // where this infers the return type. 

int main() {
	char array[] = "Bjarne Stroustrup";
	int len = 17;

	vector<char> vc(array, array + len);
	list<char> lc(vc.begin(), vc.end());

	cout << *find(array, array + len, 'S') << endl;
	myFind(array, array + len, 'q');
	int a[]{ 90,30,23,68,4 };
	find_if(a, a + 5, isOdd);

	isEven isEven; //The instance of the type can be used as a function; called: functor
	//Functor is an instance of a class, where the class defines the parenthesis operator
	//Or the "function call operator", where your instance basically then can act like a function
	cout << isEven(17) << endl;

	//Example below on what you can do with iter, so that when you call v2.begin() etc. that it knows the type
	//for (auto iter = v2.begin(); iter != v2.end(); ++iter) {
	//	cout << *iter << ' '; // print the data
	//}
	//cout << endl;
	find_if(a, a + 5, isEven);
	find_if(a, a + 5, [](int n) { return n % 2 == 0; }); //lambda expressions
	//find_if(a, a + 5, [](int n) -> bool { return n % 2 == 0; }); //If you want to specify a return type. 
	
	[] {cout << "lambda\n"; } (); //another lambda expression; () is what calls the function. 
	//Lambdas are created by the compiler by creating functors. Lambda creates a function with an overloading parenthesis. 

	auto func = [] {cout << "lambda\n"; }; //assigning a function to a variable name.
	func();

	sort(array, array + len);

	//char array[] = "Bjarne Stroustrup";
	//int len = 17;

	///*
	//	Half open range includes one range, but not the other. 
	//	In terms of this, we say the starting point is array and we are just incrementing by len.
	//*/

	//vector<char> vc(array, array + len);
	//list<char> lc(vc.begin(), vc.end());

	////find(half open range, to wherever..., looking for what?)
	////Want the function to return the type that you put in
	//find(array, array + len, 'S'); //(This may be returning 
	//find(lc.begin(), lc.end(), 'S'); //This case would hope returns an iterator to where the result is so that it is O(1)

	//find(lc.begin(), lc.end(), 'S'); //If you can't find it you can return the second parameter, b/c it falls outside the range
	////of the thing. and by returning the thing outside the range, then you know it can't possibly exist. 

	//sort(array, array + len);


}