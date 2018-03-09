/*
Justin Lin
NYU ID: jwl488
N#: 19699912
Name File: lce10
Purpose: FrogPrince and Princess
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class FrogPrince;
class Princess;

class Princess {
	friend ostream& operator<<(ostream& os, const Princess& princess);

public:
	Princess(const string& thename);
	void marries(FrogPrince& betrothered);
private:
	string name;
	FrogPrince* spouse;
};

class FrogPrince {
	friend ostream& operator<<(ostream& os, const FrogPrince& prince);
public:
	FrogPrince(const string& thename);
	const string& getName() const;
	void setSpouse(Princess& princess);

private:
	string name;
	Princess* spouse;
};

int main() {
	Princess snowy("Snow White");
	cout << snowy << endl;

	FrogPrince froggy("Froggy");
	cout << froggy << endl;

	snowy.marries(froggy);
	cout << snowy << endl;
}

//Defining
//OSTREAMS
ostream& operator<<(ostream& os, const Princess& princess) {
	os << "Princess: " << princess.name;
	if (princess.spouse) {
		os << ", spouse: " << princess.spouse->getName();
	}
	return os;
}

ostream& operator<<(ostream& os, const FrogPrince& prince) {
	os << "FrogPrince: " << prince.name;
	return os;
}


//Princess
Princess::Princess(const string& thename) : name(thename), spouse(nullptr) {}

void Princess::marries(FrogPrince& betrothed) {
	spouse = &betrothed;
	betrothed.setSpouse(*this);
}

//FROG PRINCE

FrogPrince::FrogPrince(const string& thename) : name(thename), spouse(nullptr) {}

const string& FrogPrince:: getName() const {
	return name;
}

void FrogPrince::setSpouse(Princess& princess) {
	spouse = &princess;
}



