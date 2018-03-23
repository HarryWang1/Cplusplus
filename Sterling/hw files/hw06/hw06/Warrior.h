#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

namespace WarriorCraft {
	class Noble;

	class Warrior {
	private:
		std::string name;
		int strength;
		bool employed;
		Noble* employer;

	public:
		Warrior(const std::string& theName, const int theStrength);
		~Warrior();
		//Getters
		std::string getName() const;
		int getStr() const;
		bool isEmployed() const;

		//Setters
		void setEmployed(bool status);
		void setEmployer(Noble* noble);
		void loseStr(int factor1, int factor2);//Reduces the warriors strength
		void runaway();
	};
}

#endif