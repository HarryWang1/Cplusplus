/*
int* begin(){ return data; }

int* end() { return (data + theSize)}


In order to deal with different types... you can have a class for iterator...
*/

#include <iostream>

class Iterator {
	friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
		return lhs.p != rhs.p;
	}

public:
	Iterator(){
	}

	Iterator& operator++() {
		++p;
		return *this;
	}

	int operator*() const {
		return *p;
	}

	int& operator*(){
		return *p;
	}

private:
	int* p;
};

class Vector {
public:
	Vector() :data(nullptr), theSize(0), theCapacity(0){}
	explicit Vector(size_t howMany, int val = 0) {
		theSize = howMany;
		theCapacity = howMany;
		data = new int[howMany];
		for (size_t i = 0; i < theSize; ++i) {
			data[i] = val;
		}
	}
private:
	int* data;
	int theSize;
	int theCapacity;
};