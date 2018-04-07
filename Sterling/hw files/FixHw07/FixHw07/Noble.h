#pragma once
#ifndef NOBLE_H
#define NOBLE_H

#include "Protector.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace WarriorCraft {
	/*
	NOBLE CLASS
	*/
	class Noble {
	public:
		Noble();
		Noble(const string& aname, int thestrength); //Constructor
		~Noble(); //Deconstructor
		virtual int getStrength() = 0; //Return strength
		void setStrength(int stren); //Set Strength

		string getName(); //getName

		virtual bool isAlive() = 0; //isAlive
		virtual void armyDefend(); //Calling ppl to defend
		void setAlive(bool val); // set status of alive
		
		virtual void battle(Noble& enemy) = 0; //Battle function
		virtual void loseStr(int factor1, int factor2) = 0; //Losestr calculation
	protected:
		
	private:
		string name;
		int strength;
		bool alive;
	};

	/*
	PersonWithStrength
	*/
	class PersonWithStrengthToFight : public Noble {
	public:
		PersonWithStrengthToFight();
		PersonWithStrengthToFight(const string& aname, int thestrength);
		~PersonWithStrengthToFight();
		string getName();
		bool isAlive() override;
		int getStrength() override;
		void battle(Noble& enemy) override;
		void loseStr(int factor1, int factor2) override;
	private:
	};

	/*
	Lord
	*/
	class Lord : public Noble {
	public:
		Lord(const string& aname);
		~Lord(); //Deletes the army when deconstructed
		void hires(Protector& protector); //Hires a protector for the army
		string getName();
		bool isAlive() override;
		int getStrength() override;
		void battle(Noble& enemy) override;
		void loseStr(int factor1, int factor2) override;
		void armyDefend();
	private:
		vector<Protector*> army;
	};
}	
#endif