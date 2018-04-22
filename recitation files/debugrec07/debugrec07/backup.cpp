///*
//Justin Lin
//NYU ID: jwl488
//N#: 19699912
//Name File: debugrec07
//Purpose:
//*/
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <sstream>
//using namespace std;
//
///*
//Classes and Structs
//*/
//class Course;
//class Student;
//class Registrar;
//
//class Student {
//	friend ostream& operator<<(ostream& os, const Student& rhs);
//public:
//	Student(const std::string& theName) : name(theName) {}
//	void addCourse(Course& aCourse) {
//		courses.push_back(&aCourse);
//	}
//
//	size_t findIndexCourses(const std::string& courseName) {
//		for (size_t i = 0; i < courses.size(); ++i) {
//			if (courses[i]->getName() == courseName) {
//				return i;
//			}
//		}
//		return courses.size();
//	}
//	void removeCourse(const std::string& courseName) {
//		size_t index = findIndexCourses(courseName);
//		if (index != courses.size()) {
//			for (size_t i = 0; i < courses.size(); ++i) {
//				courses[i] = courses[i + 1];
//			}
//			courses.pop_back();
//		}
//		else {
//			cout << "Course to remove not found" << endl;
//		}
//
//	}
//	std::string getName() {
//		return name;
//	}
//private:
//	std::string name;
//	vector <Course*> courses;
//};
//
//class Course {
//public:
//	Course(const std::string& theName) : name(theName) {}
//	void addStudent(Student& aStudent) {
//		students.push_back(&aStudent);
//	}
//	size_t findIndexStudent(const std::string& studentName) {
//		for (size_t i = 0; i < students.size(); ++i) {
//			if (students[i]->getName() == studentName) {
//				return i;
//			}
//		}
//		return students.size();
//	}
//
//	void removeStudent(const std::string& theName) {
//		size_t index = findIndexStudent(theName);
//		if (index != students.size()) {
//			for (size_t i = 0; i < students.size(); ++i) {
//				students[i] = students[i + 1];
//			}
//			students.pop_back();
//		}
//		else {
//			cout << "Student to remove not found" << endl;
//		}
//	}
//	void clearStudents() {
//		for (size_t i = 0; i < students.size(); i++) {
//			students[i]->removeCourse(name);
//			//Don't want to delete, b/c I want the students still in the heap, and existing
//			//even if a course gets deleted. I just want the students to forget about this course.
//		}
//	}
//	std::string getName() {
//		return name;
//	}
//private:
//	std::string name;
//	std::vector<Student*> students;
//};
//
//class Registrar {
//	friend ostream& operator<<(ostream& os, const Registrar& rhs);
//public:
//	Registrar() {}
//	/*
//	FIND METHODS
//	*/
//	size_t findStudentIndex(const std::string& studentName) {
//		for (size_t i = 0; i < courses.size(); ++i) {
//			if (students[i]->getName() == studentName) {
//				return i;
//			}
//		}
//		return students.size();
//	}
//
//	size_t findCourseIndex(const std::string& courseName) {
//		for (size_t i = 0; i < courses.size(); ++i) {
//			if (courses[i]->getName() == courseName) {
//				return i;
//			}
//		}
//		return courses.size();
//	}
//	/*
//	ADD COURSES
//	*/
//	void addCourse(const std::string& courseName) {
//		Course* tempCourse = new Course(courseName);
//		courses.push_back(tempCourse);
//	}
//
//	void addStudent(const std::string& studentName) {
//		Student* tempStudent = new Student(studentName);
//		students.push_back(tempStudent);
//	}
//
//	//ENROLL STUDEN
//	void enrollStudentInCourse(const std::string& nameStudent, const std::string& nameCourse) {
//		size_t indexOfStudent = findStudentIndex(nameStudent);
//		size_t indexOfCourse = findCourseIndex(nameCourse);
//
//		if (indexOfStudent != students.size() && indexOfCourse != courses.size()) {
//			courses[indexOfCourse]->addStudent(*students[indexOfStudent]);
//			students[indexOfStudent]->addCourse(*courses[indexOfCourse]);
//		}
//
//		if (indexOfCourse == courses.size() || indexOfStudent == students.size()) {
//			cout << "Student or course is not found" << endl;
//		}
//	}
//
//
//	void cancelCourse(const std::string& nameCourse) {
//		size_t indexOfCourse = findCourseIndex(nameCourse);
//		if (indexOfCourse != courses.size()) {
//			courses[indexOfCourse]->clearStudents();//Clears the students from the course
//			delete courses[indexOfCourse];
//			for (size_t i = indexOfCourse; i < courses.size(); ++i) {
//				courses[indexOfCourse] = courses[indexOfCourse + 1];
//			}
//			courses.pop_back();
//		}
//
//
//
//	}
//	void purge() {
//
//	}
//private:
//	vector<Student*> students;
//	vector<Course*> courses;
//};
//
//ostream& operator<<(ostream& os, const Student& rhs) {
//	os << "Student Name: " << rhs.name << endl;
//	for (size_t i = 0; i < rhs.courses.size(); ++i) {
//		os << "\t" << rhs.courses[i]->getName() << endl;
//	}
//	return os;
//}
//
//ostream& operator<<(ostream& os, const Registrar& rhs) {
//	os << "Avaliable Courses: " << endl;
//	for (size_t i = 0; i < rhs.courses.size(); ++i) {
//		os << rhs.courses[i]->getName() << ", ";
//	}
//	os << endl;
//	for (size_t j = 0; j < rhs.students.size(); ++j) {
//		os << *(rhs.students[j]);
//	}
//	return os;
//}
///*
//
///*
//Main Function
//*/
//int main() {
//	Registrar registrar;
//
//	cout << "No courses or Students added yet\n";
//	cout << registrar << endl; // or cout << registrar << endl;
//
//	cout << "AddCourse CS101.001\n";
//	registrar.addCourse("CS101.001");
//	cout << registrar << endl;
//	//    cout << registrar << endl;  // or cout << registrar << endl
//
//	cout << "AddStudent FritzTheCat\n";
//	registrar.addStudent("FritzTheCat");
//	cout << registrar << endl; // or cout << registrar << endl;
//							   //    cout << registrar << endl;  // or cout << registrar << endl
//
//	cout << "AddCourse CS102.001\n";
//	registrar.addCourse("CS102.001");
//	cout << registrar << endl; // or cout << registrar << endl;
//							   //    cout << registrar << endl;  // or cout << registrar << endl
//
//	cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
//	registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
//	cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
//	registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
//	cout << registrar << endl; // or cout << registrar << endl;
//							   //    cout << registrar << endl;  // or cout << registrar << endl
//
//	cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
//	cout << "Should fail, i.e. do nothing, since Bullwinkle is not a Student.\n";
//	registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
//	cout << registrar << endl; // or cout << registrar << endl;
//							   //    cout << registrar << endl;  // or cout << registrar << endl
//
//	cout << "CancelCourse CS102.001\n";
//	registrar.cancelCourse("CS102.001");
//	cout << registrar << endl; // or cout << registrar << endl;
//							   //    cout << registrar << endl;  // or cout << registrar << endl
//
//							   /*
//							   // [OPTIONAL - do later if time]
//							   cout << "ChangeStudentName FritzTheCat MightyMouse\n";
//							   registrar.changeStudentName("FritzTheCat", "MightyMouse");
//							   cout << registrar << endl;  // or cout << registrar << endl
//
//							   cout << "DropStudentFromCourse MightyMouse CS101.001\n";
//							   registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
//							   cout << registrar << endl;  // or cout << registrar << endl
//
//							   cout << "RemoveStudent FritzTheCat\n";
//							   registrar.removeStudent("FritzTheCat");
//							   cout << registrar << endl;  // or cout << registrar << endl
//							   */
//
//	cout << "Purge for start of next semester\n";
//	registrar.purge();
//	cout << registrar << endl; // or cout << registrar << endl;
//							   //    cout << registrar << endl;  // or cout << registrar << endl
//}
//
////void initFile(const string& filename) {
////	reprar
////
////		//Opens file
////		ifstream ifs(filename);
////	if (!ifs) {
////		cerr << "Unable to open file";
////		exit(1);   // call system to stop
////	}
////	while (getline(ifs, line)) {
////		stringstream wordStream(line);
////		while (wordStream >> word) {
////			//NOBLE LOGIC
////			if (word == "PrintReport") {
////				cout << "printReport" << endl;
////			}
////			else if (word == "AddCourse") {
////
////				cout << "AddCourse" << endl;
////			}
////			else if (word == "AddStudent") {
////				cout << "AddStudent" << endl;
////			}
////			else if (word == "EnrollStudent") {
////				cout << "EnrollSTudent" << endl;
////			}
////			else if (word == "CancelCourse") {
////				cout << "CancelCourse" << endl;
////			}
////			else if (word == "Purge") {
////				cout << "Purge" << endl;
////			}
////			else {
////
////			}
////
////		}
////	}
////	ifs.close();
////}
////
/////*/
////Functions
////*/
