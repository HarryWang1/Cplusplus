/*
Justin Lin
NYU ID: jwl488
N#: 19699912
Name File: rec5
Purpose: rec05
*/

/*
Assumptions that were told to be made in lab:
1) Change all .display() to cout <<
2) Labs and students can be only assigned to one Section.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

//Classes and Structs
class Section {
	//OSstream prototype declaration
	friend ostream& operator<<(ostream& os, const Section& rhs);
public:
	//Class student
	class student {
	public:
		//Constructor
		student(const string& theName) : name(theName) {}
		string getName() const {
			return name;
		}

		//Modifies grade, when called through lab section
		void modifyGrade(int grade, int theWeek) {
			grades[theWeek - 1] = grade;
		}
		//returns grades
		vector<int>& returnGrades() {
			return grades;
		}

	private:
		string name;
		vector <int> grades{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; // 14 -1
	};


	class timeslot {
	public:
		//Constructors
		timeslot() : weekday("None"), hour(0) {} 
		timeslot(string theWeekDay, int theHour) :weekday(theWeekDay), hour(theHour) {}

		//Variables
		string weekday;
		int hour;
	};

public:
	//Section Constructor
	Section(const string& theSectionName, const string& theDay, int theHour) : sectionName(theSectionName), time(theDay, theHour) {}

	//Section Deconstructor
	~Section() {
		cout << sectionName << " is being deleted" << endl;
		for (size_t i = 0; i < record.size(); ++i) {
			//Goes through and delete each student when it deconstructs
			cout << "Deleting: " << record[i]->getName() << endl;
			delete record[i];
		}
	}

	//Copy Constructor
	Section(const Section& theSection) {
		//Time Copy
		time.hour = theSection.time.hour;
		time.weekday = theSection.time.weekday;
		//Section Name
		sectionName = theSection.sectionName;
		//Copy and paste over student
		for (size_t i = 0; i < record.size(); ++i) {
			student* tempStudent = new student(*theSection.record[i]);
			record.push_back(tempStudent);
			
		}
	}

	//Adds student on heap and then to record
	void addStudent(const string& theName) {
		student* tempStudent = new student(theName);
		record.push_back(tempStudent);
	}

	//Returns the name fo the section
	string getSectionName() const {
		return sectionName;
	}

	//Allows modifying record, for grades
	void modifyRecord(const string& studentName, int grade, int week) {
		for (size_t i = 0; i < record.size(); ++i) {
			if (record[i]->getName() == studentName) {
				record[i]->modifyGrade(grade, week);
			}
		}
	}

private:
	vector <student*> record;
	timeslot time;
	string sectionName;
};


class LabWorker {
	//Ostream prototypes
	friend ostream& operator<<(ostream& os, const LabWorker& rhs);

public:
	//Constructor
	LabWorker(const string& theName) : name(theName), assignedSection(nullptr) {}

	//Gets the labworker assigned to a section
	void addSection(Section& sectionName) {
		assignedSection = &sectionName;
	}

	//Lets labworker add grade
	void addGrade(const string& theStudent, int grade, int theWeek) {
		assignedSection->modifyRecord(theStudent, grade, theWeek);
	}
private:
	string name;
	Section* assignedSection;
};


/*
OStream
*/
//Overload << for Section
ostream& operator<<(ostream& os, const Section& rhs) {
	//Need to convert to 12 hour time. 
	int tempTime = rhs.time.hour;
	string day = "a.m";
	if (tempTime > 12) {
		day = "p.m";
		tempTime -= 12;
	}
	os << "Section: " << rhs.sectionName << ", Time slot: [Day: " << rhs.time.weekday << ", Start time: " << tempTime << day << "], Students: ";
	if (rhs.record.empty()) {
		os << "None";
	}
	else {
		for (size_t i = 0; i < rhs.record.size(); ++i) {
			os << "\n Name: " << rhs.record[i]->getName() << ", Grades: ";
			for (int& j : rhs.record[i]->returnGrades()) {
				os << j << " ";
			}
		}
	}
	os << endl;
	return os;
}
//Overload for labworker
ostream& operator<<(ostream& os, const LabWorker& rhs) {
	if (rhs.assignedSection == nullptr) {
		return os << rhs.name << " does not have a section" << endl;
	}

	os << rhs.name << " has ";
	os << *(rhs.assignedSection);
	return os;
}

void doNothing(Section sec) { cout << sec; }

/*
Main Function
*/
int main() {

	cout << "Test 1: Defining a section\n";
	Section secA2("A2", "Tuesday", 16);
	cout << secA2 << endl;

	cout << "\nTest 2: Adding students to a section\n";
	secA2.addStudent("John");
	secA2.addStudent("George");
	secA2.addStudent("Paul");
	secA2.addStudent("Ringo");
	cout << secA2 << endl;

	cout << "\nTest 3: Defining a lab worker.\n";
	LabWorker moe("Moe");
	cout << moe << endl;

	cout << "\nTest 4: Adding a section to a lab worker.\n";
	moe.addSection(secA2);
	cout << moe << endl;

	cout << "\nTest 5: Adding a second section and lab worker.\n";
	LabWorker jane("Jane");
	Section secB3("B3", "Thursday", 11);
	secB3.addStudent("Thorin");
	secB3.addStudent("Dwalin");
	secB3.addStudent("Balin");
	secB3.addStudent("Kili");
	secB3.addStudent("Fili");
	secB3.addStudent("Dori");
	secB3.addStudent("Nori");
	secB3.addStudent("Ori");
	secB3.addStudent("Oin");
	secB3.addStudent("Gloin");
	secB3.addStudent("Bifur");
	secB3.addStudent("Bofur");
	secB3.addStudent("Bombur");
	jane.addSection(secB3);
	cout << jane << endl;

	cout << "\nTest 6: Adding some grades for week one\n";
	moe.addGrade("John", 17, 1);
	moe.addGrade("Paul", 19, 1);
	moe.addGrade("George", 16, 1);
	moe.addGrade("Ringo", 7, 1);
	cout << moe << endl;

	cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
	moe.addGrade("John", 15, 3);
	moe.addGrade("Paul", 20, 3);
	moe.addGrade("Ringo", 0, 3);
	moe.addGrade("George", 16, 3);
	cout << moe << endl;

	cout << "\nTest 8: We're done (almost)! \nWhat should happen to all those students (or rather their records?)\n";

	cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, then make sure the following call works\n";
	doNothing(secA2);
	cout << "Back from doNothing\n\n";

} // main
