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
#include <list>>
#include <sstream>
#include <array>
using namespace std;


list<char>::iterator myFind(list<char>::iterator start,
	list<char>::iterator stop, char target) {
	for (list<char>::iterator p = start; start != stop; ++p) {
		if (*p == target)
			return p;
	}
	return stop;
}

template <typename T, typename U>
T myFind(T start, T stop, U target) {
	for (T p = start; start != stop; ++p) {
		if (*p == target)
			return p;
	}
	return stop;
}

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
	cout << isEven(17) << endl;

	find_if(a, a + 5, isEven);
	find_if(a, a + 5, [](int n) { return n % 2 == 0; }); //lambda expressions
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