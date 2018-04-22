#ifndef course
#define course

#include <iostream>
#include <string>
#include <vector>

namespace BrooklynPoly {
	class student;

	class Course {
	public:
		Course(std::string& theName);
		void addStudent(student& aStudent);
		void removeStudent(student& aStudent);
		std::string getName();
	private:
		std::string name;
		student** students;
	};
}
#endif
