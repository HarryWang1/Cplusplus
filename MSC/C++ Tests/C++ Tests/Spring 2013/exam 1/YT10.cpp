#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;


class Employee{

private:
	string name;
	Employee* boss;
	vector <Employee*> staffList;


public:

	Employee(const string& name) :name(name), boss(nullptr){}

	void display() const{

		cout << "Name: " << name << "; Boss:";

		if (boss != nullptr){
			cout << boss->name << "; Staff: ";
		}

		else
			cout << "none; Staff:";

		if (staffList.size() == 0){
			cout << "none." << endl;
		}
		else{
			for (Employee* employee : staffList){
				cout << " " << employee->name;
			}
			cout << endl;
		}


	}
	bool hire(Employee& empHire){
		if (&empHire == this){ return false; }
		if (&empHire == boss){ return false; }
		if (empHire.boss){ return false; }

		else{
			staffList.push_back(&empHire);
			empHire.boss = this;
			return true;
		}
	}
	void quit(){
		if (boss){
			for (size_t i = 0; i < boss->staffList.size(); ++i){
				if (boss->staffList[i] == this){
					boss->staffList[i] = boss->staffList[boss->staffList.size() - 1];
					boss->staffList.pop_back();
				}
			}
			boss = nullptr;
		}
	}

void fire(Employee& toFire){
		for( size_t i = 0; i < staffList.size(); ++i ){
			if( staffList[i] == &toFire ){
				staffList[i]->boss = nullptr;
				staffList[i] = staffList[ staffList.size() - 1 ];
				staffList.pop_back();
			}
		}
	}
};

int main(){
		Employee groucho("Groucho");
		Employee harpo("Harpe");
		Employee chico("Chico");
		Employee zeppo("Zeppo");
		//Status
		groucho.display();
		harpo.display();
		chico.display();
		zeppo.display();
		cout << "=====\n";
		groucho.hire(harpo); // return true
		harpo.hire(groucho); // return false
		groucho.hire(zeppo); // return true
		groucho.hire(chico); // return true
		//Status
		groucho.display();
		harpo.display();
		chico.display();
		zeppo.display();
		cout << "=====\n";
		harpo.quit();
		harpo.hire(groucho);
		//Status
		groucho.display();
		harpo.display();
		chico.display();
		zeppo.display();
		cout << "=====\n";

		harpo.fire(groucho);
		groucho.fire(chico);
		zeppo.fire(groucho);

		//Status
		groucho.display();
		harpo.display();
		chico.display();
		zeppo.display();
		cout << "=====\n";

		cin.get();
}