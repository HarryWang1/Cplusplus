#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

namespace BrooklynPoly {
	class Course;

	class student {
	public:
		student(std::string& theName);
		void addCourse(Course& aCourse);
		void removeCourse(Course& aCourse);
		std::string getName();
	private:
		std::string name;
		Course** Courses;
	};
}
#endif
