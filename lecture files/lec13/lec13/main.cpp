//#include <vector>
//#include <stdlib.h>
//#include <iostream>
//using namespace std;
//
//void foo(vector<int>&v) {
//	v.at(17) = 47;
//	try {
//		int index = 0;
//		while (true) {
//			cout << v.at(index) << endl;
//			++index;
//		}
//	}
//	catch(out_of_range ex){} //Exceptions cost when they get thrown; so you rather not. 
//}
//
//int main() {
//	vector<int>v;
//	try {
//		foo(v);
//	}
//	catch (out_of_range& ex) {
//		cerr << "Caught an out_of_range: " << ex.what() << endl;
//	}
//	catch (exception& ex) {
//		cerr << "Caught an Exception: " << ex.what() << endl;
//	}
//}
//
