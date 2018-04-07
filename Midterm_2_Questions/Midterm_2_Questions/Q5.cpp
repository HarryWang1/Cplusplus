#include <iostream>
using namespace std;

/*
Create a derived Triangle Class: Triangle will have a base and height that are pointers to stuff on the heap.
*/

class Shape {
public:
	Shape(const string& s) : color(new string(s)) {}

	virtual ~Shape() { //REMINDER NEED TO MAKE THIS VIRTUAL
		/*
		Ex. 
		Shape* sp = new Triangle(...)
		delete sp; 

		This would only delete the shape in the triangle, but not delete the unsigned base and height in the triangle
		*/
		delete color;
	}

	Shape(const Shape& rhs) :color(new string(*(rhs.color))) {}

	Shape& operator=(const Shape& rhs) {
		if (this != &rhs) {
			delete color;
			color = new string(*(rhs.color));
		}
		return *this;
	}
private:
	string* color;
};

class Triangle : public Shape {
public:
	Triangle(string color, unsigned int aBase, unsigned int aHeight) : 
		Shape(color), 
		base(new unsigned int(aBase)),
		height(new unsigned int(aHeight)){}

	~Triangle() {
		delete base;
		delete height;
	}

	Triangle(const Triangle& rhs) : 
		Shape(rhs), 
		base(new unsigned int(*(rhs.base))),
		height(new unsigned int(*(rhs.height))){}

	Triangle& operator=(const Triangle& rhs) {
		if (this != &rhs) {
			Shape::operator=(rhs);
			base = (new unsigned int(*(rhs.base)));
			height = (new unsigned int(*(rhs.height)))
		}
		return *this;
	}

private:
	unsigned int* base;
	unsigned int* height;

};
int main() {

}