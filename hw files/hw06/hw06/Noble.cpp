#include "Noble.h"
#include "Warrior.h"

namespace WarriorCraft {

	std::ostream& operator<<(std::ostream& os, const Noble& rhs) {
		os << rhs.getName() << " has an army of " << rhs.getSize() << "\n";
		for (Warrior* warrior : rhs.army) {
			os << "\t" << warrior->getName() << ": " << warrior->getStr() << "\n";
		}
		return os;
	}

	Noble::Noble(const std::string& aName) : name(aName), isAlive(true) {}

	//Hires the warriors and push it onto pointer for warrior
	bool Noble::hire(Warrior& warrior){
		if (isAlive) {
			if (warrior.isEmployed() == false) {
				Warrior* const ptrwarrior = &warrior;
				ptrwarrior->setEmployed(true);
				ptrwarrior->setEmployer(this);
				army.push_back(ptrwarrior);
				return true;
			}
		}
		return false;
	}

	//Fires the warriors
	bool Noble::fire(const Warrior& warrior){
		if (isAlive && !army.empty()) {
			for (size_t i = 0; i < army.size(); ++i) {
				if (warrior.getName() == army[i]->getName()) {
					army[i]->setEmployed(false);
					std::cout << "You don't work for me anymore " << army[i]->getName() << "! -- " << name << "\n";
					while (i + 1 < army.size()) {
						army[i] = army[i + 1];
					}
					army.pop_back();
					return true;
				}
			}
		}
		return false;
	}

	//Returns the strength of the army
	int Noble::strength() const{
		int armystr = 0;
		for (size_t i = 0; i < army.size(); ++i) {
			armystr += army[i]->getStr();
		}
		return armystr;
	}

	//Reduces the strength of the army, calls each warrior and reduces their strength, if dead, reduces by factor of 0
	void Noble::loseStr(int factor1, int factor2){
		for (size_t i = 0; i < army.size(); ++i) {
			army[i]->loseStr(factor1, factor2);
		}
		if (factor1 == 0) {
			isAlive = false;
		}
	}

	//Battle Logic
	void Noble::battle(Noble& opponent){
		std::cout << opponent.name << " battles " << this->name << std::endl;
		//Gets the strength
		int noble1 = this->strength();
		int noble2 = opponent.strength();

		//First check if both are dead
		if ((!isAlive) && (!opponent.isAlive)) {
			std::cout << "Oh, NO!  They're both dead!  Yuck!\n";
		}
		//Checks if one of them is dead
		else if (!isAlive || !opponent.isAlive) {
			if (!isAlive) {
				std::cout << "He's dead, " << opponent.name << std::endl;
			}
			else {
				std::cout << "He's dead, " << name << std::endl;
			}
		}
		//If both of them have the same strength
		else if (noble1 == noble2) {
			std::cout << "Mutual Annihilation: " << opponent.name << " and " << this->name << " die at each other's hands\n";
			loseStr(0, 0);
			opponent.loseStr(0, 0);
		}
		//If both are alive and have different strength
		else {
			if (noble1 > noble2) {
				std::cout << name << " defeats " << opponent.name << std::endl;
				loseStr(noble2, noble1);
				opponent.loseStr(0, 0);
			}
			else {
				std::cout << opponent.name << " defeats " << name << std::endl;
				opponent.loseStr(noble1, noble2);
				loseStr(0, 0);
			}
		}
	}
	//Returns Name
	std::string Noble::getName() const{ return name; }
	//Returns the size of the army
	size_t Noble::getSize() const{ return army.size();}
}