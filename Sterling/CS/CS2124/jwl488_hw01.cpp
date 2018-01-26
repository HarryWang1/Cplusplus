/*
hw01
Justin Lin

Takes in an encrypted file, reads it, and decrypts it. 
Prints to console the decrypted version.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//DECRYPTS CHAR CHARACTERS, CALLED BY stringDecrypt.
char charDecrypt(const char& letter, const int& increment) {
	//DECRYPT IF THE LETTER IS LOWER-CASE
	if (islower(letter)) {
		//GETS NUMBER TO REPRESENT NEW CHAR.
		int numChar = int(letter) - increment;

		//POSITIVE NUMBER
		while (numChar < int('a')) { 
			int diffNum = int('a') - numChar; 
			numChar = int('z') + 1 - diffNum;
		}

		//NEGATIVE NUMBER
		while (numChar > int('z')) {
			int diffNum = int('z') - numChar;
			numChar = int('a') - 1 - diffNum;
		}
		return char(numChar);
	}
	return letter; //RETURNS LETTER IF CAPITAL
}

//TAKES IN STRING AND AND INCREMENTATION NUMBER, AND BREAKS IT DOWN INTO CHAR AND DECRYPT THE CHAR.
void stringDecrypt(string& lines, const int& increment) {
	for (char& c : lines) {
		c = charDecrypt(c, increment);
	}
}

//Creates a vector that stores the lines in the textfile backwards.
//Want the increment to be a reference b/c will be used later for incrementation in main.
vector <string> vectorLine(const string& textFile, int& increment) {
	//If Stream
	ifstream ifsLine(textFile);
	ifstream ifs(textFile);
	//Vectors
	vector <string> lineVector;
	vector <string> reverseLine;
	//Variables
	string line;
	getline(ifsLine, line);

	//Getting the number for incrementation
	ifs >> increment;

	//Adding to a Vector
	while (getline(ifsLine, line)) {
		lineVector.push_back(line);
	}
	
	//Reversing the Vector Lines
	for (string item : lineVector) {
		reverseLine.push_back(lineVector.back());
		lineVector.pop_back(); //Pops off the original vector to save space. 
	}
	return reverseLine;
}

/*
Decrypts text file. 
1) Calls textfile and store the lines in reversed into a vector
- At the same time also get an incrementation number from the file
2) Pass in line by line, into a stringDecrypt function to decrypt each line
3) Prints to the console each line once decrypted, before moving onto the nextline.
*/
int main() {
	//STEP 1
	int increment = 0;
	//Not const string& b/c we need the item to be modified
	for (string& item : vectorLine("encrypted.txt", increment))  {
		//STEP 2
		stringDecrypt(item, increment); //Passed in by (reference, const referenece)
		//STEP 3
		cout << item << endl;
	}
}