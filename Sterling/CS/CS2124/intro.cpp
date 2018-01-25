#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int add(int var) {
	++var;
}

void addRef(int& var) {
	++var;
}

int main() {
	std::cout << "Hello cs2124!\n";
	cout << "Hello!\n";
	cout << "Hello!" << endl;

	//return 0

	
	string s = "hi";
	//cin >> s;
	cout << s << endl;
	
	
	int x = 0;
	
	if (x == 28)
	{
		cout << "Perfect!\n";
	}
	else if (x == 6) {
		cout << "also perfect" << endl;
	}

	else {
		cout << "Imperfect" << endl;
	}

	for (int i = 1; i <= 10; ++i) {
		cout << i << ' ';
	}

	cout << endl;

	int counter = 1;
	while (counter <= 10) {
		cout << counter << ' ';
		counter++;
	}
	
	cout << endl;

	vector <int> v;

	for (int i = 0; i < 10; ++i) {
		v.push_back(i * 13);
	}

	for (int item : v) {
		cout << item << ' ';
	}

	cout << endl;
	for (int item : v) {
		item += 3;
		cout << item;
	}
	cout << endl;

	ifstream ifs("jabberwocky.txt");
	string word;
	ifs >> word;
	cout << word << endl;
	while (ifs >> word) {
		cout << word << endl;
	}
	/*
	ifstream ifsChar("jabberwocky.txt");
	char word;
	ifsChar >> word; //!!! BUT THE >> Will skip the white space, which will cause it to read .txt and print each char without space. 
	cout << word << endl;
	while (ifs >> word) {
		cout << word << endl;
	}*/

	ifstream ifsChar("jabberwocky.txt");
	char c;
	//Below is the code that would tell the >> to not skip the whitespace. 
	//ifsChar >> noskipws;
	ifsChar >> c;
	while (ifsChar >> c)
	{
		cout << c;
	}
	cout << endl;

	ifstream ifsLine("jabberwocky.txt");
	string line;
	getline(ifsLine, line);
	cout << line << endl;
	while (getline(ifsLine, line)) {
		cout << line << endl;
	}

}


