/*
Justin Lin
NYU ID: jwl488
N#: 19699912
Name File: Lec8Vector
*/
#include <iostream>
using namespace std;

class Vector {
public:
	Vector() {
		theSize = 0;
		theCapacity = 1;
		data = new int[1]; //Creating a list of 1 int. 
	}
	//Copy control
	~Vector() { delete[] data; } //This is how you clear an array for delete.
	Vector(const Vector& rhs) {
		theSize = rhs.theSize;
		theCapacity = rhs.theCapacity;
		data = new int[theCapacity];
		for (size_t index = 0; index < theSize; ++index) {
			data[index] = rhs.data[index];
		}
	}

	Vector& operator=(const Vector& rhs) {
		//prevent self assignment
		if (this != &rhs) {
			//free up
			delete[] data;
			//allocating and copying
			theSize = rhs.theSize;
			theCapacity = rhs.theCapacity;
			data = new int[theCapacity];
			for (size_t index = 0; index < theSize; ++index) {
				data[index] = rhs.data[index];
			}
		}
		//return yourself
		return *this;
	}

	void push_back(int val) {
		if (theSize == theCapacity) {
			theCapacity *= 2;
			int* nextArray = new int[theCapacity];
			for (size_t i = 0; i < theSize; ++i) {
				nextArray[i] = data[i];
			}
			delete[] data;
			data = nextArray;
		}
		data[theSize] = val;
		++theSize;
	}
	size_t size() const {return theSize;}

	void pop_back() {--theSize;}

	void clear() { theSize = 0; }
	//Square brackets?

	int* operator[] (size_t index) { return &data[index];}
	int* operator[] (size_t index) const { return &data[index]; }
private:
	size_t theSize;
	size_t theCapacity;
	int* data;
};

int main() {
	Vector v; // Not templated. Our vector class can only hold ints.
	Vector v2(v);
	Vector v3;
	v3 = v;
	//you can also do forloop without the ending braces if just one line
	for (size_t i = 0; i < v.size(); ++i) cout << v[i] << endl;


	v[0] = 100;
	v[17]; //v.operator[]
	v.operator[](17);
	/*
	v.push_back(17);
	v.push_back(17);
	v.push_back(17);
	v.push_back(17);
	*/
}