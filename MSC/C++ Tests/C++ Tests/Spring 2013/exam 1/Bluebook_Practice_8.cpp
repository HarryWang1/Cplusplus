/*
Bluebook Practice
Question 9

Sterling tells us a few things, write these out to help yourself
Employee's may have a staff
	-Every "Employee" has a vector of pointers to other "Employee"s
	-This pointer cannot be "this"
	-This pointer cannot be their immediate boss
		-The immediate boss is an Employee pointer
			-Wouldn't make sense to have the boss be unable to 
			  do anything on its own.
	-Can't hire someone who is already part of another person's staff
	-The quit method


I should mention, don't include "getters" and "setters" unless you
	absolutely need them, mainly because the whole point of having
	private attributes of a class is so that you can't access or
	modify them. Getters and setters defeat this purpose.
*/
#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Employee{
private:
	//Easiest thing to do is write the private attributes at the top of the class
	//This allows you to come back easily
	//The prompt tells us 2 things:
		//An employee can have a staff
		//An employee can have a boss
		//It goes without saying the Employee has a name
	string name;
	Employee* boss;
	vector<Employee*> staff;
public:
	//Constructor
		//Don't forget to handle any single-variable attributes!
		//This includes the Employee* "boss" we made up above
		//If you don't include boss in the constructor you have a "dangling pointer"
		//Sterling hates "Memory Leak" and "Dangling Pointers" and will take off a lot of points if they show up
	Employee( const string& name )
		: name(name), boss(nullptr){}
		//There are multiple ways to do the constructor, like including a boss in the parameter list, but that leads
		//to a lot of other complications, so this is the one he wants


	//Display (I like to do this first)
		//Simple enough, just follow the format given
	void display() const{
		cout << "Name: " << name
			<< "; Boss: ";

		//Need a boss check
		//ASIDE: if( boss != nullptr ){} is the same as if( boss ){}
			//Basically "If boss exists" and "If boss does not point to nothing"
		if( boss ){
			cout << boss->name << "; Staff: ";
		}
		else
			cout << "none; Staff:";
		//Need a staff check, so we use size()
		if( staff.size() == 0 ){
			cout << " none.\n";
		}
		else{
			for( Employee* empPtr : staff ){
				cout << " " << empPtr->name ;
			}
			cout << ".\n";
		}
	}

	//I usually like to use the "test program" to guide myself to see what
	//methods I need inside a class. Next up would be "hire"

	//Hire
		//He has examples there that say "return true/return false"
		//This tells you that it will return a "bool" type
		//BUT the method will be modifying a value before returning the bool!
	bool hire( Employee& empToHire ){
		//Remeber what we CAN'T do
			//Hire ourselves
			//Hire our boss
			//Hire someone who already has a boss
		//Checks need to be implemented for all
		if( &empToHire == this ){ return false; }
		if( &empToHire == boss ){ return false; }
		if( empToHire.boss ){ return false; }
			//These will  be checked first and if any are true it will complete
			//the method
		//Now that all 3 checks are done we can continue with the "hire" method, which is rather simple
		staff.push_back( &empToHire );
		empToHire.boss = this;
		return true;
		//Since all the checks have been implemented we can now push_back the empToHire
		//The method will exit if any of the returns happen.
	}

	//quit() is a bit tricky. It requires some digging and vector manipulation to do, but in the end is rather
	//simple when you understand it.
	void quit(){
		//First things first, DO NOT REMOVE THE BOSS POINTER BEFORE REMOVING THEM FROM THE VECTOR
		//If you do this you will not be able to remove "this" from the boss's vector

		if( boss ){//This will be the check for the "nothing happens" part of the prompt
			for( size_t i = 0; i < boss->staff.size(); ++i ){
				if( boss->staff[i] == this ){//Checks to see where "this" is in the boss's staff
					//Vector location i will now point to whatever the last value of the vector was pointing to.
					boss->staff[i] = boss->staff[ boss->staff.size() - 1 ];
					//The last value of the vector (index "i" is ALSO pointing size()-1 is pointing to) needs to be cleared
					//It DOES NOT need to be "deleted" because it is NOT on the heap
						//Deleting the pointer will delete the value that the pointer is pointing too
						//Basically, delete is only used to clear pointers that are on the heap so that there are no
						//MEMORY LEAKS
					boss->staff.pop_back();//Will clear the last value of the vector
				}
			}
			boss = nullptr;
		}
	}
};
int main(){
	Employee groucho("Groucho");
	Employee harpe( "Harpe");
	Employee chico("Chico");
	Employee zeppo("Zeppo");
	//Status
	groucho.display();
	harpe. display();
	chico. display();
	zeppo. display();
	cout << "=====\n";
	groucho.hire(harpe); // return true
	harpe.hire(groucho); // return false
	groucho.hire(zeppo); // return true
	groucho.hire(chico); // return true
	//Status
	groucho.display();
	harpe. display();
	chico.display();
	zeppo. display();
	cout << "=====\n";
	harpe.quit();
	harpe.hire(groucho);
	//Status
	groucho.display();
	harpe. display();
	chico. display();
	zeppo. display();
	cout << "=====\n";
}