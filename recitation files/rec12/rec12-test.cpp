/*
Justin Lin
Rec 12
4/21/18
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


class List {
	struct Node;
	friend ostream& operator<<(ostream& os, List myList) {
		myList.printList();
		return os;
	}

public:
	List() : frontptr(nullptr), backptr(nullptr), sizeList(0) {}

	//List(List& rhs) {
	//	Node* cursor = rhs.frontptr;
	//	while (cursor->next != nullptr) {
	//		push_back(cursor->data);
	//	}
	//}
	//~List() {
	//	Node* cursor = frontptr;
	//	Node* cursorNext = frontptr->next;
	//	while (cursor->next != nullptr) {
	//		delete cursor;
	//		cursor = cursorNext;
	//		cursorNext = cursor->next;
	//	}
	//}

	class Iterator {
		friend List;
		friend Node;

		friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
			return lhs.p != rhs.p;
		}
	public:
		Iterator(Node* p) : p(p) {}

		Iterator& operator++() {
			p = p->next;
			return *this;
		}
		const int operator*() const {
			return p->data;
		}
		int& operator*() {
			return p->data;
		}
	private:
		Node* p;
	};



	void push_front(int data) {

		if (sizeList == 0) {
			frontptr = createNode(data);
			backptr = frontptr;
		}
		else {
			Node* oldfront = frontptr;
			frontptr = createNode(data);

			oldfront->prev = frontptr;
			frontptr->next = oldfront;
		}
		++sizeList;
	}

	Iterator insert(Iterator insert, int data) {
		if (insert.p == nullptr) {
			push_back(data);
			return Iterator(backptr);
		}
		else if (insert.p == frontptr) {
			push_front(data);
			return Iterator(frontptr);
		}
		else {
			Node newNode = Node(data, insert.p->prev, insert.p);
			insert.p->prev->next = &newNode;
			insert.p->prev = &newNode;
		}
	}

	Iterator erase(Iterator eraseIns) {
		if (sizeList == 0) {//if 0
			return Iterator(nullptr);
		}
		if (sizeList == 1) {//if size 1
			delete eraseIns.p;
			--sizeList;
			return Iterator(nullptr);
		}
		Node* answer = eraseIns.p->next;
		if (eraseIns.p == frontptr) { //in the beginning
			frontptr = eraseIns.p->next;
			eraseIns.p->next->prev = nullptr;
			delete eraseIns.p;
			--sizeList;
			return Iterator(answer);
		}
		//in the middle
		eraseIns.p->prev->next = eraseIns.p->next;
		eraseIns.p->next->prev = eraseIns.p->prev;
		delete eraseIns.p;
		--sizeList;
		return Iterator(answer);


	}

	void pop_front() {
		if (sizeList > 1) {
			Node* oldfront = frontptr;
			frontptr = oldfront->next;
			frontptr->prev = nullptr;

			oldfront->next = nullptr;
			delete oldfront;
		}
		else {
			delete frontptr;
			frontptr = nullptr;
			backptr = nullptr;
		}
		--sizeList;
	}

	void push_back(int data) {

		if (sizeList == 0) {
			frontptr = createNode(data);
			backptr = frontptr;
		}
		else {
			backptr->next = createNode(data);
			backptr->next->prev = backptr;
			backptr = backptr->next;
		}
		++sizeList;
	}

	void pop_back() {
		if (sizeList > 1) {
			Node* oldback = backptr; //store as temp...
			backptr = oldback->prev; // back ptr updated...
			oldback->prev = nullptr;
			delete oldback;

			backptr->next = nullptr;

		}
		else {
			delete frontptr;
			frontptr = nullptr;
			backptr = nullptr;
		}
		--sizeList;
	}

	Node* front() {
		return frontptr;
	}

	Node* back() {
		return backptr;
	}

	size_t size() {
		return sizeList;
	}

	void printList() {
		Node* cursor = frontptr;
		if (frontptr != nullptr) cout << cursor->data << " ";
		while (cursor->next != nullptr) {
			cursor = cursor->next;
			cout << cursor->data << " ";

		}

	}

	void clear() {
		while (sizeList > 1) {
			pop_back();
		}
		--sizeList;
	}

	int& operator[](int index) {
		Node* cursor = frontptr;
		while (index > 0) {
			--index;
			cursor = cursor->next;
		}
		return cursor->data;
	}
	int operator[](int index) const {
		Node* cursor = frontptr;
		while (index > 0) {
			--index;
			cursor = cursor->next;
		}
		return cursor->data;
	}

	Iterator begin() {
		Iterator result(frontptr);
		return result;
	}
	Iterator end() { return Iterator(nullptr); }

	const Iterator begin() const { return Iterator(frontptr); }
	const Iterator end() const { return Iterator(nullptr); }

private:
	struct Node {
		Node& operator+=(int increment) {
			++data;
		}

		Node(int data = 0, Node* prev = nullptr, Node* next = nullptr) : data(data), prev(prev), next(next) {}
		int data;
		Node* next;
		Node* prev;
	};

	Node* createNode(int data) {
		// 1. make a node for the data
		Node* p = new Node(data);
		return p;
	}

private:
	size_t sizeList;
	Node* frontptr;
	Node* backptr;
};

void printListInfo(List myList) {
	myList.printList();
	cout << "\n";
}

void doNothing(List myList) {
	List test(myList);
}

int main() {

	// Task 1
	cout << "\n------Task One------\n";
	List myList;
	cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
	for (int i = 0; i < 10; ++i) {
		cout << "myList.push_back(" << i*i << ");\n";
		myList.push_back(i*i);
		printListInfo(myList);
	}
	cout << "===================\n";
	cout << "Remove the items with pop_back\n";
	while (myList.size()) {
		printListInfo(myList);
		myList.pop_back();
	}
	cout << "===================\n";

	// Task2
	cout << "\n------Task Two------\n";
	cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
	for (int i = 0; i < 10; ++i) {
		cout << "myList2.push_front(" << i*i << ");\n";
		myList.push_front(i*i);
		printListInfo(myList);
	}
	cout << "===================\n";
	cout << "Remove the items with pop_front\n";
	while (myList.size()) {
		printListInfo(myList);
		myList.pop_front();
	}
	cout << "===================\n";

	// Task3
	cout << "\n------Task Three------\n";
	cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
	for (int i = 0; i < 10; ++i) {
		myList.push_back(i*i);
	}
	printListInfo(myList);
	cout << "Now clear\n";
	myList.clear();
	cout << "Size: " << myList.size() << ", list: ";
	printListInfo(myList);
	cout << endl;
	cout << "===================\n";

	// Task4
	cout << "\n------Task Four------\n";
	cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
	for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
	cout << "Display elements with op[]\n";
	for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
	cout << endl;
	cout << "Add one to each element with op[]\n";
	for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
	cout << "And print it out again with op[]\n";
	for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
	cout << endl;

	// Task 5
	cout << "\n------Task Five------\n";
	cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
	myList.clear();
	for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
	printListInfo(myList);
	cout << "Now display the elements in a ranged for\n";
	for (int x : myList) cout << x << ' ';
	cout << endl;
	cout << "And again using the iterator type directly:\n";
	for (List::Iterator iter = myList.begin(); iter != myList.end(); ++iter) {
		cout << *iter << ' ';
	}
	cout << endl;
	cout << "WOW!!! (I thought it was cool.)\n";

	// Task 6
	cout << "\n------Task Six------\n";
	cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
	myList.clear();
	for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
	printListInfo(myList);
	cout << "Filling an empty list with insert at begin(): "
		<< "i*i for i from 0 to 9\n";
	myList.clear();
	for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
	printListInfo(myList);
	// ***Need test for insert other than begin/end***
	cout << "===================\n";

	// Task 7
	cout << "\n------Task Seven------\n";
	cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
	myList.clear();
	for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
	cout << "Erasing the elements in the list, starting from the beginning\n";
	while (myList.size()) {
		printListInfo(myList);
		myList.erase(myList.begin());
	}
	// ***Need test for erase other than begin/end***
	cout << "===================\n";

	// Task 8
	cout << "\n------Task Eight------\n";
	cout << "Copy control\n";
	cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
	myList.clear();
	for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
	printListInfo(myList);
	cout << "Calling doNothing(myList)\n";
	doNothing(myList);
	cout << "Back from doNothing(myList)\n";
	printListInfo(myList);

	//cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
	//List listTwo;
	//for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
	//printListInfo(listTwo);
	//cout << "listTwo = myList\n";
	//listTwo = myList;
	//cout << "myList: ";
	//printListInfo(myList);
	//cout << "listTwo: ";
	//printListInfo(listTwo);
	//cout << "===================\n";
}
