#include "Warrior.h"
#include "Noble.h"

namespace WarriorCraft {
	Warrior::Warrior(const std::string & theName, const int theStrength) :
		name(theName), strength(theStrength), employed(false) {}

	Warrior::~Warrior()
	{
	}

	//Getters
	std::string Warrior::getName() const {
		return name;
	}
	int Warrior::getStr() const {
		return strength;
	}
	bool Warrior::isEmployed() const {
		return employed;
	}

	void Warrior::runaway() {
		std::cout << name << "flees in terror, abandoning his lord," << employer->getName() << std::endl;
		employer->fire(*this);
	}

	//Setters
	void Warrior::setEmployed(bool status) {
		if (status == false) {
			employer = NULL;
		}
		employed = status;
	}
	void Warrior::setEmployer(Noble* noble)
	{
		employer = noble;
	}

	void Warrior::loseStr(int factor1, int factor2) {
		if (factor2 != 0) {
			strength = strength - (strength * factor1 / factor2);
		}
		else {
			strength = strength * factor2;
		}
	}
}
