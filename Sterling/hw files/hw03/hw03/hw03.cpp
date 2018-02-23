/*
Justin Lin
Name File: hw03
Purpose: Model a medieval game
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

//Sets up struct for warrior, which includes their name and strength.
class Warrior {
	/*Friend Functions*/
	friend void status(const vector <Warrior>& warr);
	friend size_t findWarriorIndex(const string& warrName, const vector <Warrior>& warriorList);
	friend void battle(const string& aWarr, const string& bWarr, vector<Warrior>& listofWarriors);

	/*SubClasses*/
	class Weapon {
	public:
		Weapon() {
			strength = 0;
		}
		Weapon(string wName, int stren) : weapName(wName), strength(stren) {}
		string weapName;
		int strength;
	};

/*Warrior Class main definitions*/
public:
	Warrior(const string& theName, const string& weapon, int theStrength) : name(theName), weap(weapon, theStrength) {}
private:
	string name;
	Weapon weap;
};

/*
Prototype Functions and Descriptions
*/

//Initializes the file and reads from it line by line, calling either status or battle depending on the first keyword per line. Closes file at the end.
void initializeWarriors(const string& filename);
//Checks the status of each warrior
void status(const vector <Warrior>& warr);
//Puts warriors to battle. 
void battle(const string& aWarr, const string& bWarr, vector<Warrior>& listofWarriors);
//Helps find a warrior and their index
size_t findWarriorIndex(const string& warrName, const vector <Warrior>& warriorList);

/*
Main Function
*/
int main() {
	string file = "battle.txt";
	initializeWarriors(file);
}

/*/
Functions
*/
void initializeWarriors(const string& filename) {
	string line;
	string word;
	vector <Warrior> warriors;

	//Opens file
	ifstream warstream(filename);
	if (!warstream) {
		cerr << "Unable to open file";
		exit(1);   // call system to stop
	}

	while (getline(warstream, line)) {
		stringstream wordStream(line);
		while (wordStream >> word) {
			if (word == "Warrior") {
				string name, weapon, stren;
				wordStream >> name >> weapon >>  stren;
				Warrior initWarrior(name, weapon, stoi(stren));
				warriors.push_back(initWarrior);
			}
			if (word == "Battle") {
				string aWarrior, bWarrior;
				wordStream >> aWarrior >> bWarrior;
				battle(aWarrior, bWarrior, warriors);
			}
			if (word == "Status") {
				cout << "There are: " << warriors.size() << " warriors." << endl;
				status(warriors);
			}
		}
	}
	warstream.close();
}

void status(const vector <Warrior>& warr) {
	for (size_t i = 0; i < warr.size(); ++i) { cout << "Warrior: " << warr[i].name << ", Weapon: " << warr[i].weap.weapName << ", " << warr[i].weap.strength << endl; }
}

void battle(const string& aWarr, const string& bWarr, vector<Warrior>& listofWarriors) {
	//Finds the indexes of the warriors to do battle
	size_t indexAwarr = findWarriorIndex(aWarr, listofWarriors);
	size_t indexBwarr = findWarriorIndex(bWarr, listofWarriors);

	//Declares who is battling who
	cout << listofWarriors[indexAwarr].name << " battles " << listofWarriors[indexBwarr].name << endl;

	if (listofWarriors[indexAwarr].weap.strength == 0 && listofWarriors[indexBwarr].weap.strength == 0) {
		cout << "Oh, NO!They're both dead! Yuck!" << endl;
	}
	else if (listofWarriors[indexAwarr].weap.strength == 0 || listofWarriors[indexBwarr].weap.strength == 0) {
		if (listofWarriors[indexAwarr].weap.strength == 0) {
			cout << "He's dead, " << listofWarriors[indexBwarr].name << endl;
		}
		else {
			cout << "He's dead, " << listofWarriors[indexAwarr].name << endl;
		}
	}
	else if (listofWarriors[indexAwarr].weap.strength == listofWarriors[indexBwarr].weap.strength) {
		cout << "Mutual Annihilation: " << listofWarriors[indexAwarr].name << " and " << listofWarriors[indexBwarr].name << " die at each other's hands." << endl;
		listofWarriors[indexAwarr].weap.strength = 0;
		listofWarriors[indexBwarr].weap.strength = 0;
	}
	else {
		int aInitStrength = listofWarriors[indexAwarr].weap.strength;
		int bInitStrength = listofWarriors[indexBwarr].weap.strength;

		listofWarriors[indexAwarr].weap.strength = aInitStrength - bInitStrength;
		listofWarriors[indexBwarr].weap.strength = bInitStrength - aInitStrength;

		if (listofWarriors[indexAwarr].weap.strength < 0) { listofWarriors[indexAwarr].weap.strength = 0; }
		if (listofWarriors[indexBwarr].weap.strength < 0) { listofWarriors[indexBwarr].weap.strength = 0; }

		if (listofWarriors[indexAwarr].weap.strength > listofWarriors[indexBwarr].weap.strength) {
			cout << listofWarriors[indexAwarr].name << " defeats " << listofWarriors[indexBwarr].name << endl;
		}
		else {
			cout << listofWarriors[indexBwarr].name << " defeats " << listofWarriors[indexAwarr].name << endl;
		}
	}

}

size_t findWarriorIndex(const string& warrName, const vector <Warrior>& warriorList) {
	for (size_t warrior = 0; warrior < warriorList.size(); ++warrior) {
		if (warrName == warriorList[warrior].name) {
			return warrior;
		}
	}
	return warriorList.size();
}