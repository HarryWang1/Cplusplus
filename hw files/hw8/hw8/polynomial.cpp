/*
Justin Lin

HW8
*/
#include "polynomial.h"

Node::Node(int data = 0, Node* prev = nullptr, Node* next = nullptr) : data(data), prev(prev), next(next) {}

// accessors    
int Node::getData() { return data; }
Node* Node::getNext() { return next; }
Node* Node::getPrev() { return prev; }
// mutators
void Node::setData(int data) { this->data = data; }
void Node::setNext(Node* next) { this->next = next; }
void Node::setPrev(Node* prev) { this->prev = prev; }


Polynomial::Polynomial(vector<int> init) : header(new Node()), tail(header), length(init.size()) {
	if (init.size() == 0) {
		header->setData(NULL);
	}
	else {
		size_t index = init.size() - 1;
		Node* cursor = header;
		for (size_t i = 0; i < init.size(); ++i) {
			cursor->setData(init[index]);
			if (i + 1 < init.size()) {
				cursor->setNext(new Node());
				cursor->getNext()->setPrev(cursor);
				cursor = cursor->getNext();
			}
			--index;
			tail = cursor;
		}
	}
}

//Copy Constructor
Polynomial::Polynomial(const Polynomial& init) : header(new Node()),
tail(header), length(init.length) {

	Node* initCursor = init.header;
	Node* cursor = header;
	for (size_t i = 0; i < init.length; ++i) {
		cursor->setData(initCursor->getData()); //Sets the data... 
		if (i + 1 < init.length) { //If there is still room...
			cursor->setNext(new Node()); //Create a new node...
			cursor->getNext()->setPrev(cursor); //set that new node prev to this...
			cursor = cursor->getNext(); //Move the cursor over...
		}
		initCursor = initCursor->getNext();//Move the cursor over
		tail = cursor;
	}
}

Polynomial& Polynomial::operator=(const Polynomial& rhs) {
	if (this != &rhs) {
		//1. free up resources
		for (size_t i = 0; i < length; i++) { pop_back(); }
		//2. allocate new resources
		//3. copy over
		Node* cursor = rhs.header;
		for (size_t j = 0; j < rhs.length; j++) {
			push_back(cursor->getData());
			cursor = cursor->getNext();
		}
	}
	return *this;
}

Polynomial::~Polynomial() {
	Node* cursor = header;
	size_t loop = length;
	for (size_t i = 0; i < loop; ++i) {
		pop_back();
	}
}

Polynomial Polynomial::operator+(const Polynomial& rhs) {
	Polynomial result(rhs);
	return result += *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
	Node* cursor = header;
	Node* rhsCursor = rhs.header;

	size_t loopLength = length;
	if (rhs.length > length) {
		loopLength = rhs.length;
	}

	for (size_t i = 0; i < loopLength; ++i) {
		int insert = cursor->getData() + rhsCursor->getData();
		if (insert != 0) { cursor->setData(insert); }
		/*
		Calculation if Polynomials are of Different sizes.
		*/
		if (cursor->getNext() != nullptr) {
			cursor = cursor->getNext();
		}
		else { cursor = &Node(0); }

		if (rhsCursor->getNext() != nullptr) {
			rhsCursor = rhsCursor->getNext();
		}
		else { rhsCursor = &Node(0); }
	}
	return *this;
}

bool Polynomial::operator==(Polynomial rhs) {
	if (rhs.length != length) { return false; }
	for (size_t i = 0; i < length; ++i) {
		Node* cursor = header;
		Node* rhsCursor = rhs.header;

		if (cursor->getData() != rhsCursor->getData()) {
			return false;
		}
	}
	return true;
}

bool Polynomial::operator!=(Polynomial rhs) {
	return !(*this == rhs);
}

void Polynomial::push_back(int data) {
	if (length == 0) {
		header->setData(data);
		++length;
	}
	else {
		tail->setNext(new Node(data));
		tail->getNext()->setPrev(tail);
		tail = tail->getNext();
		++length;
	}
}

int Polynomial::pop_back() {
	int data = tail->getData();
	if (length == 1) {
		delete header;
		header = nullptr;
		tail == nullptr;
		return data;
	}
	Node* temp = tail;
	tail = tail->getPrev();
	delete temp;
	tail->setNext(nullptr);
	--length;
	return data;
}

int Polynomial::evaluate(int n) {
	double answer = 0;
	Node* cursor = header;
	int counter = 0;
	while (cursor != nullptr) {
		answer += (cursor->getData() * (pow(n, counter)));
		++counter;
		cursor = cursor->getNext();
	}
	return answer;
}

ostream &operator<<(ostream& os, const Polynomial& rhs) {
	Node* cursor = rhs.tail;
	int exponent = rhs.length - 1;
	while (cursor) {
		os << cursor->getData();
		if (exponent > 0) {
			if (exponent > 1) os << "x^" << exponent;
			else os << "x";
			--exponent;
		}
		if (cursor->getPrev() != nullptr) {
			os << " + ";
		}
		cursor = cursor->getPrev();
	}
	return os;
}

void doNothing(Polynomial temp) {}