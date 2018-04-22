/*
Justin Lin
NYU ID: jwl488
N#: 19699912
Name File: rec02
Purpose: To sort and maintain the names of chemical formulas along with their structure and makeup.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/*
Structs
*/
struct mFormula {
	mFormula(const string& name, int carb, int hydro) : carbon(carb), hydrogen(hydro) {
		formulaName.push_back(name);
	}
	vector <string> formulaName;
	int carbon;
	int hydrogen;
};

/*
Prototype Main Function
*/
//Initializes and reads the file, calling the other functions to add the necessary formula to a list holding the structs.
void initFile(const string& fileName);
//Adds structs to a list of structs, depending on its C and H content.
void addToVector(const string& name, int carbon, int hydro, vector <mFormula>& list);
//Prints out a list of structs in Carbon order. 
void printVector(const vector<mFormula>& list);
//Scans for index of where carbon and hydrogen matches, if not, returns the size of the list. 
size_t scanIndex(int carbon, int hydro, const vector <mFormula>& list);

/*
Main Function
*/
int main() {
	string file = "chem.txt";
	initFile(file);
}

/*/
Functions
*/
void initFile(const string& fileName) {
	string line;
	string fName; //Names
	string chemFormula;//Formula consisting of C and H. 
	int carbonAmt;
	int hydroAmt;

	char C;
	char H;

	vector <mFormula> listFormulas;

	ifstream chemstream(fileName);
	if (!chemstream) {
		cerr << "Unable to open file";
		exit(1);   // call system to stop
	}

	while (getline(chemstream, line)) {
		istringstream wordStream(line);
		while (wordStream >> fName >> C >> carbonAmt >> H >> hydroAmt) {
			addToVector(fName, carbonAmt, hydroAmt, listFormulas);
		}
	}
	chemstream.close();
	printVector(listFormulas);
}

void addToVector(const string& name, int carbon, int hydro, vector <mFormula>& list) {
	if (list.empty()) {
		mFormula formula(name, carbon, hydro);
		list.push_back(formula);
	}
	else {
		size_t index = scanIndex(carbon, hydro, list);
		if (index == list.size()) {
			mFormula formula(name, carbon, hydro);
			list.push_back(formula);
		}
		else {
			list[index].formulaName.push_back(name);
		}
	}
}

size_t scanIndex(int carbon, int hydro, const vector <mFormula>& list) {
	for (size_t i = 0; i < list.size(); ++i) {
		if (list[i].carbon == carbon && list[i].hydrogen == hydro) {
			return i;
		}
	}
	return list.size();
}

void printVector(const vector<mFormula>& list) {
	int maxCarbon = 0;
	int counter = 0;
	for (size_t i = 0; i < list.size(); ++i) {
		if (list[i].carbon > maxCarbon) {
			maxCarbon = list[i].carbon;
		}
	}

	while (counter <= maxCarbon) {
		for (size_t j = 0; j < list.size(); ++j) {
			if (list[j].carbon == counter) {
				cout << 'C' << list[j].carbon << 'H' << list[j].hydrogen;
				for (size_t k = 0; k < list[j].formulaName.size(); ++k) {
					cout << " " << list[j].formulaName[k];
				}
				cout << endl;
			}
		}
		counter++;
	}
}