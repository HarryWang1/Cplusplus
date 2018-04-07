#pragma once
#ifndef PROTECTOR_H
#define PROTECTOR_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace WarriorCraft {
	class Protector {
	public:
		Protector(const string& aname, int theStrength);
	private:
		string name;
		int strength;
	};

	class Wizard : public Protector{
	public:
		Wizard(const string& aname, int thestrength);
	private:
	};

	class Warriors : public Protector {
	public:
		Warriors(const string& aname, int thestrength);
	private:
		string name;
		int strength;
	};

	class Swordsman : public Warriors {
	public:
		Swordsman(const string& aname, int thestrength);
	private:
	};

	class Archer : public Warriors {
	public:
		Archer(const string& aname, int thestrength);
	private:
	};

}
#endif