/*
Car:
- store Parts as an array
- Number of items
- Big Three Implemented

Parts:
- int pointer
Constructor(which takes a part number)
- Big 3

Engine:
- Horse power as a double pointer
- Takes Engine Part Number (int)
- Horsepower for the engine (**)
- Assignment operator
*/

class Parts;
class Engine;
class Car;

class Parts {
public:
	Parts(int num) : partNum(new int(num)) {}
	virtual ~Parts() {delete partNum;}
	Parts(const Parts& rhs) {
		//delete partNum;
		//int* tempPtr = new int(*rhs.partNum);
		partNum = new int(*rhs.partNum);
	}
private:
	int* partNum;
};

class Engine : public Parts {
public:
	Engine(int engPart, double horsePow) : 
	 /*enginePart(engPart),*/ Part(engPart), horsePower(new double(horsePow)){}
	Engine& operator=(Engine& rhs) {
		if (this != &rhs) {
			delete horsePower;
			horsePower = rhs.horsePower;
			enginePart = rhs.enginePart;
		}
	}
private:
	//int enginePart;
	double* horsePower;
};

class Car {
public:
	Car() {

	}
	virtual ~Car() {
		delete[] parts;
	}

	Car(const Car& car) {
		delete[] parts;
		parts = new Parts(car.numParts);
		for (size_t i = 0; i < car.numParts; ++i) {
			parts[i] = car.parts[i];
		}
	}
private:
	int numParts;
	Parts* parts;
};