/*
  Recitation 06
  CS2124

  Focus: Dynamic arrays and copy control.
 */

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Position {
	friend ostream& operator<<(ostream& os, const Position& rhs) {
		os << '[' << rhs.title << ',' << rhs.salary << ']';
		return os;
	}
public:
	Position(const string& aTitle, double aSalary)
		: title(aTitle), salary(aSalary) {}
	const string& getTitle() const { return title; }
	double getSalary() const { return salary; }
	void changeSalaryTo(double d) { salary = d; }
	//void display(ostream& os = cout) const {
	//	os << '[' << title << ',' << salary << ']';
	//}
private:
	string title;
	double salary;
}; // class Position

class Entry {
	friend ostream& operator<<(ostream& os, const Entry& rhs) {
		os << rhs.name << ' ' << rhs.room << ' ' << rhs.phone << ", ";
		os << *rhs.pos;
		return os;
	}

public:
	Entry(const string& aName, unsigned aRoom, unsigned aPhone,
		Position& aPosition)
		: name(aName), room(aRoom), phone(aPhone), pos(&aPosition) {
	}
	//void display(ostream& os = cout) const {
	//	os << name << ' ' << room << ' ' << phone << ", ";
	//	pos->display(os);
	//}
	const string& getName() const { return name; }
	const unsigned& getPhone() const { return phone; }
private:
	string name;
	unsigned room;
	unsigned phone;
	Position* pos;
}; // class Entry

class Directory {
	friend ostream& operator<<(ostream& os, const Directory& rhs) {
		for (size_t i = 0; i < rhs.size; ++i) {
			os << *rhs.entries[i];	
			os << endl;
		}
		
		return os;
	}
public:
	Directory() {
		++capacity;
		entries = new Entry*[capacity];
	}
	//Copy Constructor
	Directory(const Directory& rhs) {
		size = rhs.size;
		capacity = rhs.capacity;
		entries = new Entry*[capacity];
		//Entry* new_Entry = new Entry();
		for (size_t index = 0; index < size; ++index) {
			Entry* new_entry = new Entry(*rhs.entries[index]);
			entries[index] = new_entry;

			/*Entry* new_entry = rhs.entries[index];
			entries[index] = new_entry;*/
		}
	}

	//Destructor
	~Directory() {
		cout << "***Deleting... [Destructor successfully called]" << endl;
		for (size_t i = 0; i < size; ++i) {
			delete entries[i];
		}
		delete[] entries;
	}

	//Assignment Operator
	Directory& operator=(const Directory& rhs) {
		//prevent self assignment
		if (this != &rhs) {
			//free up
			for (size_t i = 0; i < size; ++i) {
				delete entries[i];
			}
			delete[] entries;
			//allocating and copying
			size = rhs.size;
			capacity = rhs.capacity;
			entries = new Entry*[capacity];
			for (size_t index = 0; index < size; ++index) {
				Entry* new_entry = new Entry(*rhs.entries[index]);
				entries[index] = new_entry;
			}
		}
		//return yourself
		return *this;
	}

	void add(const string& name, unsigned room, unsigned ph, Position& pos) {
		if (size == capacity) {
			// something is missing!!!  Add it!		
			capacity *= 2;
			Entry** nextArray = new Entry*[capacity];
			for (size_t i = 0; i < size; ++i) {
				nextArray[i] = entries[i];
			}
			delete[] entries;
			entries = nextArray;
		} // if
		entries[size] = new Entry(name, room, ph, pos);
		++size;
	} // add

	//void display(ostream& os = cout) const {
	//	for (size_t i = 0; i < size; ++i) {
	//		entries[i]->display(os);
	//		os << endl;
	//	}
	//}

	unsigned operator[] (string name) const {
		for (size_t i = 0; i < size; ++i) {
			string compare = entries[i]->getName();
			if (name == (compare)) {
				return (entries[i]->getPhone());
			}
		}

		return capacity;
	}

private:
	Entry** entries = nullptr;
	size_t size = 0;
	size_t capacity = 0;
}; // class Directory

void doNothing(Directory dir) { cout << dir; } // dir.display();

int main() {

	// Note that the Postion objects are NOT on the heap.
	Position boss("Boss", 3141.59);
	Position pointyHair("Pointy Hair", 271.83);
	Position techie("Techie", 14142.13);
	Position peon("Peonissimo", 34.79);

	// Create a Directory
	Directory d;
	d.add("Marilyn", 123, 4567, boss);
	cout << d;// d.display();

	Directory d2 = d;	// What function is being used??
	d2.add("Gallagher", 111, 2222, techie);
	d2.add("Carmack", 314, 1592, techie);
	cout << d2; // d2.display();

	cout << "Calling doNothing\n";
	doNothing(d2);
	cout << "Back from doNothing\n";

	Directory d3;
	d3 = d2;
	//// Should display 1592
	cout << d2["Carmack"] << endl;

} // main
