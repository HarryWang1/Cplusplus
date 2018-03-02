/*
Justin Lin
Hw05
Learning Dynamic Memory
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
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
	~Warrior() {}
	//Getters
	string getName() const { return name; }
	int getStr() const { return strength; }
	bool isEmployed() const { return employed; }

	//Setters
	void setEmployed(bool status) { employed = status; } //sets whether or not the warrior is employed
	void loseStr(int factor1, int factor2) {
		if (factor2 != 0) {
			strength = strength - (strength * factor1 / factor2);
		}
		else {
			strength = strength * factor2;
		}

	}//Reduces the warriors strength
};

class Noble {
	friend ostream& operator<<(ostream& os, const Noble& rhs);
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
					cout << "You don't work for me anymore " << army[i]->getName() << "! -- " << name << "\n";
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
	void loseStr(int factor1, int factor2) {
		for (size_t i = 0; i < army.size(); ++i) {
			army[i]->loseStr(factor1, factor2);
		}
		if (factor1 == 0) {
			isAlive = false;
		}
	}

	//Battle Logic
	void battle(Noble& opponent) {
		cout << opponent.name << " battles " << this->name << endl;
		//Gets the strength
		int noble1 = this->strength();
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
			cout << "Mutual Annihilation: " << opponent.name << " and " << this->name << " die at each other's hands\n";
			loseStr(0, 0);
			opponent.loseStr(0, 0);
		}
		//If both are alive and have different strength
		else {
			if (noble1 > noble2) {
				cout << name << " defeats " << opponent.name << endl;
				loseStr(noble2, noble1);
				opponent.loseStr(0, 0);
			}
			else {
				cout << opponent.name << " defeats " << name << endl;
				opponent.loseStr(noble1, noble2);
				loseStr(0, 0);
			}

		}

	}
	//Returns Name
	string getName() const {
		return name;
	}
	//Returns the size of the army
	size_t getSize() const {
		return army.size();
	}


};

/*
OsStreams
*/
ostream& operator<<(ostream& os, const Noble& rhs) {
	os << rhs.getName() << " has an army of " << rhs.getSize() << "\n";
	for (Warrior* warrior : rhs.army) {
		os << "\t" << warrior->getName() << ": " << warrior->getStr() << "\n";
	}
	return os;
}


/*
Declarations
*/
void initializeWarriors(const string& file); //Inits the file and logic for the textfile
size_t findIndexWarrior(const vector <Warrior*>& warriors, const string& name); //Helps find the index of a warrior; returns size of vector if not found.
size_t findIndexNoble(const vector <Noble*>& nobles, const string& name); //Helps find the index of a noble; returns size of vector if not found.

int main() {
	string file = "nobleWarriors.txt";
	initializeWarriors(file);
}

size_t findIndexWarrior(const vector <Warrior*>& warriors, const string& name) {
	for (size_t i = 0; i < warriors.size(); ++i) {
		if (name == warriors[i]->getName()) {
			return i;
		}
	}
	return warriors.size();
}

size_t findIndexNoble(const vector <Noble*>& nobles, const string& name) {
	for (size_t i = 0; i < nobles.size(); ++i) {
		if (name == nobles[i]->getName()) {
			return i;
		}
	}
	return nobles.size();
}

void initializeWarriors(const string& filename) {
	string line;
	string word;
	vector <Warrior*> warriors;
	vector <Noble*> nobles;
	vector <Warrior*> unemployed;

	//Opens file
	ifstream warstream(filename);
	if (!warstream) {
		cerr << "Unable to open file";
		exit(1);   // call system to stop
	}

	while (getline(warstream, line)) {
		stringstream wordStream(line);
		while (wordStream >> word) {
			//NOBLE LOGIC
			if (word == "Noble") {
				string nameNoble;;
				wordStream >> nameNoble;
				//Initialize the noble
				size_t nobleCheck = findIndexNoble(nobles, nameNoble);
				if (nobleCheck == nobles.size()) {
					Noble* ptr = new Noble(nameNoble);
					nobles.push_back(ptr);
				}
				else {
					cout << "There is already a noble by that name" << endl;
				}
			}
			//WARIOR LOGIC
			else if (word == "Warrior") {
				string nameWarrior;
				int str;
				wordStream >> nameWarrior >> str;
				//Initialize warrior
				size_t WarriorCheck = findIndexWarrior(warriors, nameWarrior);
				if (WarriorCheck == warriors.size()) {
					Warrior* ptr = new Warrior(nameWarrior, str);
					warriors.push_back(ptr);
				}
				else {
					cout << "There is already a warrior by that name" << endl;
				}

			}
			//HIRE LOGIC
			else if (word == "Hire") {
				string nobleEmployer, warriorWorker;
				wordStream >> nobleEmployer >> warriorWorker;
				//Hire
				size_t indexOfN = findIndexNoble(nobles, nobleEmployer);
				size_t indexOfW = findIndexWarrior(warriors, warriorWorker);

				if (indexOfN != nobles.size() && indexOfW != warriors.size()) {
					nobles[indexOfN]->hire(*warriors[indexOfW]);
					for (size_t i = 0; i < unemployed.size(); ++i) {
						if (warriorWorker == unemployed[i]->getName()) {
							while (i + 1 < unemployed.size()) {
								unemployed[i] = unemployed[i + 1];
							}
							unemployed.pop_back();
						}
					}
				}
				else {
					cout << "Error: Warrior or Nobles doesn't exist" << endl;
				}
			}
			//FIRE LOGIC
			else if (word == "Fire") {
				string nobleEmployer, warriorWorker;
				wordStream >> nobleEmployer >> warriorWorker;
				//Hire
				size_t indexOfN = findIndexNoble(nobles, nobleEmployer);
				size_t indexOfW = findIndexWarrior(warriors, warriorWorker);

				if (indexOfN != nobles.size() && indexOfW != warriors.size()) {
					unemployed.push_back(warriors[indexOfW]);
					bool ctrl = !nobles[indexOfN]->fire(*warriors[indexOfW]);
					if (ctrl) {
						cout << "The warrior is not in the noble's army" << endl;
					}


				}
				else {
					cout << "The warrior/noble does not exist" << endl;
				}
			}
			//STATUS LOGIC
			else if (word == "Status") {
				//Status
				if (nobles.size() != 0) {
					cout << "Status\n=====\nNobles: " << endl;
					for (Noble* n : nobles) {
						cout << *n;
					}
					cout << "Unmployed Warriors:" << endl;
					if (unemployed.size() == 0) {
						cout << "NONE" << endl;
					}
					else {
						for (size_t i = 0; i < unemployed.size(); ++i) {
							cout << unemployed[i]->getName() << ": " << unemployed[i]->getStr() << endl;
						}
					}
				}
				else {
					cout << "Status\n=====\nNobles: " << endl;
					cout << "NONE" << endl;
					cout << "Unemployed" << endl;
					cout << "NONE" << endl;
				}


			}
			//BATTLE LOGIC
			else if (word == "Battle") {
				string Noble1, Noble2;
				wordStream >> Noble1 >> Noble2;
				//Send to battle

				size_t indexOfN1 = findIndexNoble(nobles, Noble1);
				size_t indexOfN2 = findIndexNoble(nobles, Noble2);

				if (indexOfN1 != nobles.size() && indexOfN2 != nobles.size()) {
					nobles[indexOfN2]->battle(*nobles[indexOfN1]);
				}
				else {
					cout << "One or both nobles don't exist; Battle" << endl;
				}
			}

			//CLEAR LOGIC
			else if (word == "Clear") {
				for (size_t j = 0; j < warriors.size(); ++j) {
					delete warriors[j];
				}

				for (size_t i = 0; i < nobles.size(); ++i) {
					delete nobles[i];
				}

				nobles.clear();
				warriors.clear();
				unemployed.clear();
			}
			else {
				cout << "Unrecognized command in text file" << endl;
			}
		}
	}
	warstream.close();
}