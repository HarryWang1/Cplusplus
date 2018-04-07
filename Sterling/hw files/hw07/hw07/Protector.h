#pragma once
#ifndef PROTECTOR_H
#define PROTECTOR_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace WarriorCraft {
	class Noble;

	class Protector {
	public:
		Protector(const string& aname, int theStrength);
		virtual int getStrength() = 0;
		virtual void battle() {};
		virtual void getHired(Noble& employer) = 0;
		string getEmployerName();
		string getName();
		void battleDeclaration();
		virtual void loseStr(int factor1, int factor2) = 0;
	private:
		string name;
		int strength;
		Noble* employer;
	};

	class Wizard : public Protector{
	public:
		Wizard(const string& aname, int thestrength);
		int getStrength() override;
		void getHired(Noble& employer) override;
		void battle();
		void loseStr(int factor1, int factor2) override;
	private:
	};

	class Warriors : public Protector {
	public:
		Warriors(const string& aname, int thestrength);
		int getStrength() override;
		void getHired(Noble& employer) = 0;
		void battle() = 0;
		
	private:
		string name;
		int strength;
	};

	class Swordsman : public Warriors {
	public:
		Swordsman(const string& aname, int thestrength);
		int getStrength() override;
		void getHired(Noble& employer) override;
		void battle();
		void loseStr(int factor1, int factor2) override;

	private:
	};

	class Archer : public Warriors {
	public:
		Archer(const string& aname, int thestrength);
		int getStrength() override;
		void getHired(Noble& employer) override;
		void loseStr(int factor1, int factor2) override;
		void battle();
	private:
	};

}
#endif