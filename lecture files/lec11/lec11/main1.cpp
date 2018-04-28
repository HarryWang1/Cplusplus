/*
Justin Lin
NYU ID: jwl488
N#: 19699912
Name File: lec11
Purpose: 
*/

#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

using namespace std;

/*
Classes and Structs
*/

pair<int, string> foo() {
	return make_pair(42, "the answer");
}

int main() {
	auto result = foo();
	cout << result.first << ": " << result.second << endl;
}
/*
Prototype Main Function
*/

/*
Main Function
*/
int main() {

}

/*/
Functions
*/
