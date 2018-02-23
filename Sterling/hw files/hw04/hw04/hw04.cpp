/*
Justin Lin
Hw04
Create battle simulation with warriors and nobles
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*
Class Declaration
*/

class Warrior {
private:
	string name;
	int strength;
	bool employed;

public:
	Warrior(const string& theName, const int theStrength) :
		name(theName), strength(theStrength), employed(false) {}

	//Getters
	string getName() const {return name;}
	int getStr() const {return strength;}
	bool isEmployed() const {return employed;}

	//Setters
	void setEmployed(bool status) { employed = status; } //sets whether or not the warrior is employed
	void loseStr(int factor) {strength = strength * factor;}//Reduces the warriors strength
};

class Noble {
private:
	string name;
	vector<Warrior*> army;
	bool isAlive;

public:
	Noble(const string& aName) : name(aName), isAlive(true) {}

	//Hires the warriors and push it onto pointer for warrior
	bool hire(Warrior& warrior) {
		if (isAlive) {
			if (warrior.isEmployed() == false) {
				Warrior* const ptrwarrior = &warrior;
				army.push_back(ptrwarrior);
				return true;
			}
		}
		return false;
	}

	//Fires the warriors
	bool fire(const Warrior& warrior) {	
		if (isAlive && !army.empty()) {
			for (size_t i = 0; i < army.size(); ++i) {
				if (warrior.getName() == army[i]->getName()) {  
					army[i]->setEmployed(false);
					cout << army[i]->getName() << ", you're fired! -- " << name << "\n";
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
	int strength() const {
		int armystr = 0;
		for (size_t i = 0; i < army.size(); ++i) {
			armystr += army[i]->getStr();
		}
		return armystr;
	}

	//Reduces the strength of the army, calls each warrior and reduces their strength, if dead, reduces by factor of 0
	void loseStr(int factor) {
		for (size_t i = 0; i < army.size(); ++i) {
			army[i]->loseStr(factor);
		}
		if (factor == 0) {
			isAlive = false;
		}
	}

	//Battle Logic
	void battle(Noble& opponent) {
		cout << this->name << " battles " << opponent.name << endl;
		//Gets the strength
		int noble1 = strength();
		int noble2 = opponent.strength();

		//First check if both are dead
		if ((!isAlive) && (!opponent.isAlive)) {
			cout << "Oh, NO!  They're both dead!  Yuck!\n";
		}
		//Checks if one of them is dead
		else if (!isAlive || !opponent.isAlive) {
			if (!isAlive) {
				cout << "He's dead, " << opponent.name << endl;
			}
			else {
				cout << "He's dead, " << name << endl;
			}
		}
		//If both of them have the same strength
		else if (noble1 == noble2) {
			cout << "Mutual Annihilation: " << name << " and " << opponent.name << " die at each other's hands\n";
			loseStr(0);
			opponent.loseStr(0);
		}
		//If both are alive and have different strength
		else {
			if (noble1 > noble2) {
				cout << name << " defeats " << opponent.name << endl;
				loseStr(noble2/noble1);
				opponent.loseStr(0);
			}
			else {
				cout << opponent.name << " defeats " << name << endl;
				opponent.loseStr(noble1 / noble2);
				loseStr(0);
			}

		}

	}

	//Displays status of the army under the noble.
	void display() const {
		cout << name << " has an army of " << army.size() << "\n";
		for (Warrior* warrior : army) {
			cout << "\t" << warrior->getName() << ": " << warrior->getStr() << "\n";
		}
	}
};

int main() {
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);
}
