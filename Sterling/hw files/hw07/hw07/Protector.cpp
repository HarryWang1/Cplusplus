#include "Protector.h"

namespace WarriorCraft {
	Protector::Protector(const string& aName, int theStrength) 
		: name(aName), strength(theStrength) {}
	Wizard::Wizard(const string& aname, int thestrength) :
		Protector(aname, thestrength) {}
	Warriors::Warriors(const string& aname, int thestrength) :
		Protector(aname, thestrength) {}
	Swordsman::Swordsman(const string& aname, int thestrength) :
		Warriors(aname, thestrength) {}
	Archer::Archer(const string& aname, int thestrength) :
		Warriors(aname, thestrength) {}

}