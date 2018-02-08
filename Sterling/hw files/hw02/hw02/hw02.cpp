/*
Justin Lin
Name File: hw02
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
struct Warrior {
	Warrior(const string& theName, int theStrength) : name(theName), strength(theStrength) {}
	string name;
	int strength;
};

/*
Prototype Functions and Descriptions
*/

//Initializes the file and reads from it line by line, calling either status or battle depending on the first keyword per line. Closes file at the end.
void initializeWarriors(const string& filename);
//Calculates the rules for a battle of the game. The Vector is not a const due to strength of the warriors that need to be change in battle
void battle(const string& aWarr, const string& bWarr, vector<Warrior>& listofWarriors);
//Prints the status of the warriors
void status(const vector <Warrior>& warr);
//Helps find the warriors' index when called to battle.
size_t findWarriorIndex(const string& warrName, const vector<Warrior>& warriorList);

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
				string name, stren;
				wordStream >> name >> stren;
				Warrior initWarrior(name, stoi(stren));
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

void battle(const string& aWarr, const string& bWarr, vector<Warrior>& listofWarriors) {

	//Finds the indexes of the warriors to do battle
	size_t indexAwarr = findWarriorIndex(aWarr, listofWarriors);
	size_t indexBwarr = findWarriorIndex(bWarr, listofWarriors);

	//Checks to make sure the warriors are in the 
	if (indexAwarr == listofWarriors.size()) {
		cout << "Warrior " << aWarr << " does not exist!" << endl;
	}
	if (indexBwarr == listofWarriors.size()) {
		cout << "Warrior " << aWarr << " does not exist!" << endl;
	}

	//Declares who is battling who
	cout << listofWarriors[indexAwarr].name << " battles " << listofWarriors[indexBwarr].name << endl;

	//All the if-statements calculating the different states of battle
	if (listofWarriors[indexAwarr].strength == 0 && listofWarriors[indexBwarr].strength == 0) {
		cout << "Oh, NO!They're both dead! Yuck!" << endl;
	}
	else if (listofWarriors[indexAwarr].strength == 0 || listofWarriors[indexBwarr].strength == 0) {
		if (listofWarriors[indexAwarr].strength == 0) {
			cout << "He's dead, " << listofWarriors[indexBwarr].name << endl;
		}
		else {
			cout << "He's dead, " << listofWarriors[indexAwarr].name << endl;
		}
	}
	else if (listofWarriors[indexAwarr].strength == listofWarriors[indexBwarr].strength) {
		cout << "Mutual Annihilation: " << listofWarriors[indexAwarr].name << " and " << listofWarriors[indexBwarr].name << " die at each other's hands." << endl;
		listofWarriors[indexAwarr].strength = 0;
		listofWarriors[indexBwarr].strength = 0;
	}
	else {
		int aInitStrength = listofWarriors[indexAwarr].strength;
		int bInitStrength = listofWarriors[indexBwarr].strength;

		listofWarriors[indexAwarr].strength = aInitStrength - bInitStrength;
		listofWarriors[indexBwarr].strength = bInitStrength - aInitStrength;

		if (listofWarriors[indexAwarr].strength < 0) { listofWarriors[indexAwarr].strength = 0; }
		if (listofWarriors[indexBwarr].strength < 0) { listofWarriors[indexBwarr].strength = 0; }

		if (listofWarriors[indexAwarr].strength > listofWarriors[indexBwarr].strength) {
			cout << listofWarriors[indexAwarr].name << " defeats " << listofWarriors[indexBwarr].name << endl;
		}
		else {
			cout << listofWarriors[indexBwarr].name << " defeats " << listofWarriors[indexAwarr].name << endl;
		}
	}
}

void status(const vector <Warrior>& warr) {
	for (size_t i = 0; i < warr.size(); ++i) {cout << "Warrior: " << warr[i].name << ", strength: " << warr[i].strength << endl;}
}

size_t findWarriorIndex(const string& warrName, const vector<Warrior>& warriorList) {
	for (size_t i = 0; i < warriorList.size(); ++i) {
		if (warrName == warriorList[i].name) {
			return i;
		}
	}
	return warriorList.size();

}