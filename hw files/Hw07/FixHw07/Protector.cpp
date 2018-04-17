#include "Protector.h"
#include "Noble.h"

namespace WarriorCraft {
	/*
	Protectors
	*/
	Protector::Protector(const string& aName, int theStrength)
		: name(aName), strength(theStrength), employer(nullptr) {}
	int Protector::getStrength() {
		return strength;
	}
	void Protector::getHired(Noble& boss) {employer = &boss;}
	bool Protector::isEmployed() { return !(employer == nullptr); }
	string Protector::getEmployerName() { return employer->getName(); }
	string Protector::getName() { return name; }
	void Protector::battleDeclaration() { cout << getName() << " says: Take that in the name of my lord, " << getEmployerName() << endl; }

	void Protector::loseStr(int factor1, int factor2) {
		if (factor2 != 0) {
			strength = strength - (strength * factor1 / factor2);
		}
		else {
			strength = strength * factor2;
		}	
	}
	/*
	Wizards
	*/
	Wizard::Wizard(const string& aname, int thestrength) :
		Protector(aname, thestrength) {}
	int Wizard::getStrength() {
		return Protector::getStrength();
	}
	void Wizard::getHired(Noble& boss) {
		Protector::getHired(boss);
	}
	void Wizard::battle() {
		cout << "Poof \n";
	}

	void Wizard::loseStr(int factor1, int factor2) {
		Protector::loseStr(factor1, factor2);
	}

	bool Wizard::isEmployed() { return Protector::isEmployed(); }

	/*
	Warriors
	*/
	Warriors::Warriors(const string& aname, int thestrength) :
		Protector(aname, thestrength) {}
	int Warriors::getStrength() {
		return Protector::getStrength();
	}


	/*
	Swordsman
	*/
	Swordsman::Swordsman(const string& aname, int thestrength) :
		Warriors(aname, thestrength) {}
	int Swordsman::getStrength() {
		return Protector::getStrength();
	}
	void Swordsman::battle() {
		cout << "Clang! ";
		Protector::battleDeclaration();
	}
	void Swordsman::getHired(Noble& boss) {
		Protector::getHired(boss);
	}
	void Swordsman::loseStr(int factor1, int factor2) {
		Protector::loseStr(factor1, factor2);
	}
	bool Swordsman::isEmployed() { return Protector::isEmployed(); }

	/*
	Archers
	*/
	Archer::Archer(const string& aname, int thestrength) :
		Warriors(aname, thestrength) {}
	int Archer::getStrength() {
		return Protector::getStrength();
	}
	void Archer::battle() {
		cout << "Twang! ";
		Protector::battleDeclaration();
	}
	void Archer::getHired(Noble& boss) {
		Protector::getHired(boss);
	}
	void Archer::loseStr(int factor1, int factor2) {
		Protector::loseStr(factor1, factor2);
	}
	bool Archer::isEmployed() { return Protector::isEmployed(); }

}