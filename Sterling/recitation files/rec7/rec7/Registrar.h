#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <iostream>
#include <string>
#include <vector>

namespace BrooklynPoly {
	class student;
	class course;

	class Registrar {
		//friend std::ostream& operator<<(std::ostream& os);
	public:
		Registrar();
		void initFile(std::string filename);
		void addCourse(std::string courseName);
		void addStudent(std::string studentName);
		void printReport();
		void enrollStudentInCourse(std::string nameStudent, std::string nameCourse);
		void cancelCourse(std::string nameCourse);
	private:
		vector<student*> students;
		vector<course*> courses;
	};
}
#endif
