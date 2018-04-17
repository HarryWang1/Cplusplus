#ifndef NOBLE_H
#define NOBLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

namespace  WarriorCraft {
	class Warrior;

	class Noble {
		friend std::ostream& operator<<(std::ostream& os, const Noble& rhs);
	private:
		std::string name;
		std::vector<Warrior*> army;
		bool isAlive;

	public:
		Noble(const std::string& aName);

		//Hires the warriors and push it onto pointer for warrior
		bool hire(Warrior& warrior);

		//Fires the warriors
		bool fire(const Warrior& warrior);

		//Returns the strength of the army
		int strength() const;

		//Reduces the strength of the army, calls each warrior and reduces their strength, if dead, reduces by factor of 0
		void loseStr(int factor1, int factor2);

		//Battle Logic
		void battle(Noble& opponent);
		//Returns Name
		std::string getName() const;
		//Returns the size of the army
		size_t getSize() const;
	};

}

#endif