#include "Noble.h"

namespace WarriorCraft {
	/*
	Noble
	*/
	Noble::Noble() {}
	Noble::Noble(const string & aname, int thestrength) : name(aname), strength(thestrength), alive(true) {}
	Noble::~Noble() {}

	//Getters and Setters
	string Noble::getName() { return name; }
	void Noble::setStrength(int stren) { strength = stren; }
	int Noble::getStrength() { return strength; }
	bool Noble::isAlive() { return alive; }
	void Noble::setAlive(bool val) { alive = val; }
	void Noble :: loseStr(int factor1, int factor2) {
		if (factor2 != 0) {
			strength = strength - (strength * factor1 / factor2);
		}
		else {
			strength = strength * factor2;
		}
	}

	//Battle Logic Common
	void Noble::battle(Noble& opponent) {
		std::cout << getName() << " battles " << opponent.getName() << std::endl;
		//Gets the strength
		int noble1 = this->getStrength();
		int noble2 = opponent.getStrength();

		//First check if both are dead
		if ((!isAlive()) && (!opponent.isAlive())) {
			std::cout << "Oh, NO!  They're both dead!  Yuck!\n";
		}
		//Checks if one of them is dead
		else if (!isAlive() || !opponent.isAlive()) {
			if (!isAlive()) {
				std::cout << "He's dead, " << opponent.getName() << std::endl;
			}
			else {
				std::cout << "He's dead, " << getName() << std::endl;
			}
		}
		//If both of them have the same strength
		else if (noble1 == noble2) {
			std::cout << "Mutual Annihilation: " << opponent.getName() << " and " << this->getName() << " die at each other's hands\n";
			loseStr(0, 0);
			opponent.loseStr(0, 0);
		}
		//If both are alive and have different strength
		else {
			if (noble1 > noble2) {
				std::cout << getName() << " defeats " << opponent.getName() << std::endl;
				loseStr(noble2, noble1);
				opponent.loseStr(0, 0);
			}
			else {
				std::cout << opponent.getName() << " defeats " << getName() << std::endl;
				opponent.loseStr(noble1, noble2);
				loseStr(0, 0);
			}
		}
	}

	/*
	Personwithstrengthtofight
	*/
	PersonWithStrengthToFight::PersonWithStrengthToFight() {}
	PersonWithStrengthToFight::PersonWithStrengthToFight(const string & aname, int thestrength) :
		Noble(aname, thestrength) {}
	PersonWithStrengthToFight::~PersonWithStrengthToFight() {}
	string PersonWithStrengthToFight::getName() { return Noble::getName(); }
	int PersonWithStrengthToFight::getStrength() { return Noble::getStrength(); }
	bool PersonWithStrengthToFight::isAlive() { return Noble::isAlive(); }
	void PersonWithStrengthToFight::battle(Noble& opponent) { return Noble::battle(opponent); }
	void PersonWithStrengthToFight::loseStr(int factor1, int factor2) { return Noble::loseStr(factor1, factor2); }


	/*
	Lord
	*/
	Lord::Lord(const string & aname) :
		Noble(aname, 0) {}
	Lord::~Lord()
	{
	}
	void Lord::hires(Protector& protector)
	{
		army.push_back(&protector);
		protector.getHired(*this);
	}
	bool Lord::isAlive() { return Noble::isAlive(); }
	string Lord::getName() { return Noble::getName(); }

	int Lord::getStrength() {
		int armystr = 0;
		for (size_t i = 0; i < army.size(); ++i) {
			armystr += army[i]->getStrength();
		}
		Noble::setStrength(armystr);
		return armystr;
	}

	void Lord::battle(Noble& opponent) { return Noble::battle(opponent); }

	void Lord::loseStr(int factor1, int factor2) { 
		for (size_t i = 0; i < army.size(); ++i) {
			army[i]->loseStr(factor1, factor2);
		}
		if (factor1 == 0) {
			setAlive(false);
		}
	}
}


