#include "student.h"
#include "course.h"
#include <iostream>
#include <string>
#include <vector>


namespace BrooklynPoly {
	class student;
	class Course;

	class Registrar {
	public:
		Registrar::Registrar() {
			std::string filename = "file.txt";
			initFile(filename);
		}
		void Registrar::initFile(std::string filename) {

		}
		void Registrar::addCourse(std::string CourseName) {

		}
		void Registrar::addStudent(std::string studentName) {

		}
		void Registrar::printReport() {

		}
		void Registrar::enrollStudentInCourse(std::string nameStudent, std::string nameCourse) {

		}
		void Registrar::cancelCourse(std::string nameCourse) {

		}
	private:
		std::vector<student*> students;
		std::vector<Course*> Courses;
	};
}
