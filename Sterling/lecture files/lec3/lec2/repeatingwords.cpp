/*
lec03
Justin Lin


*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Word {
	string token;
	vector <int> positions;
};

int main() {
	vector <Word> vs;
	ifstream ifs("jabberwocky.txt");
	if (!ifs) {
		cerr << "Unable to open file";
		exit(1);   // call system to stop
	}


	ifs.close();
}