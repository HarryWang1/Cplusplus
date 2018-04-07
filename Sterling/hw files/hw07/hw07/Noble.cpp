#include "Noble.h"

namespace WarriorCraft {
	Noble::Noble()
	{
	}
	Noble::Noble(const string & aname, int thestrength) : name(aname), strength(thestrength)
	{
	}
	Noble::~Noble()
	{
	}
	void Noble::battle(Noble & enemy)
	{
	}
	PersonWithStrengthToFight::PersonWithStrengthToFight()
	{
	}
	PersonWithStrengthToFight::PersonWithStrengthToFight(const string & aname, int thestrength) :
		Noble(aname, thestrength)
	{
	}
	PersonWithStrengthToFight::~PersonWithStrengthToFight()
	{
	}
	void PersonWithStrengthToFight::battle(Noble & enemy)
	{
	}
	Lord::Lord(const string & aname) :
		Noble(aname, 0)
	{
	}
	Lord::~Lord()
	{
	}
	void Lord::battle(Noble & enemy)
	{
	}
	void Lord::hires(Protector & protector)
	{
	}
}

