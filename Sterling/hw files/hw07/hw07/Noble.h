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
		Noble(const string& aname, int thestrength);
		~Noble();
		virtual int getStrength() = 0;
		void setStrength(int stren);

		string getName();

		virtual bool isAlive() = 0;
		void setAlive(bool val);
		
		virtual void battle(Noble& enemy) = 0; 
		virtual void loseStr(int factor1, int factor2) = 0;
		//-1 means both are dead, or that one is dead. 
		//0 means mutual annilation
		//1 means continue to battle
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
		~Lord();
		void hires(Protector& protector);
		string getName();
		bool isAlive() override;
		int getStrength() override;
		void battle(Noble& enemy) override;
		void loseStr(int factor1, int factor2) override;
	private:
		vector<Protector*> army;
	};
}	
#endif