#pragma once
#ifndef NOBLE_H
#define NOBLE_H

#include "Protector.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace WarriorCraft {
	class Noble {
	public:
		Noble();
		Noble(const string& aname, int thestrength);
		~Noble();
		virtual void battle(Noble& enemy);
	private:
		string name;
		int strength;
	};

	class PersonWithStrengthToFight : public Noble {
	public:
		PersonWithStrengthToFight();
		PersonWithStrengthToFight(const string& aname, int thestrength);
		~PersonWithStrengthToFight();
		void battle(Noble& enemy) override;
	private:
	};

	class Lord : public Noble {
	public:
		Lord(const string& aname);
		~Lord();
		void battle(Noble& enemy) override;
		void hires(Protector& protector);
	private:
		vector<Protector*> army;
	};
}	
#endif