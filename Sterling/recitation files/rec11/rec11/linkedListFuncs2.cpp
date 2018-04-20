/*
Justin Lin
N:19699912
REC 11

Code to work on Rec 11.
*/

#include <cstdlib> // To allow NULL if no other includes
#include <vector>
#include <iostream>
using namespace std;


struct Node {
	Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
	int data;
	Node* link;
};

void print(Node* print) {
	Node* cursor = print;
	while (cursor != nullptr) {
		cout << (cursor->data) << " ";
		cursor = cursor->link;
	}
	cout << endl;
}

void printAdd(Node* print) {
	Node* cursor = print;
	while (cursor != nullptr) {
		cout << (cursor) << " ";
		cursor = cursor->link;
	}
	cout << endl;
}

void listInsertHead(Node*& headPtr, int entry) {
	headPtr = new Node(entry, headPtr);
}

// Should free up your nodes, of course...
void listClear(Node*& headPtr) {
	while (headPtr != NULL) {
		//Node* next = headPtr->next;
		Node* next = headPtr->link;
		free(headPtr);
		headPtr = next;
	}
	headPtr = NULL;
}

// This might be useful for setting up test cases. Feel free to use it
// or not as you like. Example of using would be:
// Node* myList = listBuild({1, 4, 9, 16}); // builds a list of: 1 4 9 16
Node* listBuild(const vector<int>& vals) {
	Node* result = nullptr;
	for (size_t index = vals.size(); index > 0; --index) {
		listInsertHead(result, vals[index - 1]);
	}
	return result;
}



void splice(Node* insertList, Node* whereToInsert) {
	cout << "=============SPLICE FUNCTION====================\n\n" << endl;
	if (insertList == nullptr || whereToInsert == nullptr) {
		cout << "Something was null" << endl;
		return;
	}
	//BEFORE DATA
	cout << "BEFORE DATA LIST TO INSERT INTO" << endl;
	print(whereToInsert); //PRINT WHERE TO INSERT

	cout << "WHAT WE ARE INSERTING" << endl;
	
	print(insertList); //PRINT WHERE TO INSERT


	if (whereToInsert->link == nullptr) { //IF WHERE TO INSERT NEXT IS A NULLPTR JUST INSERT THE LIST
		whereToInsert->link = insertList; //SET NEXT TO INSERT LIST AND BERAK
		return;
	}

	Node* tempHold = whereToInsert->link; //HOLD TEMP ON THE WHERETOINSERT LINK

	whereToInsert->link = insertList; //Set to next list

	Node* cursor = whereToInsert;
	while (cursor->link != nullptr) {
		cursor = cursor->link;
	}
	cursor->link = tempHold;

	cout << "AFTER WE INSERT" << endl;
	print(whereToInsert);
	cout << "=============END SPLICE FUNCTION====================\n\n" << endl;
}

Node* compareTwo(Node*& startingPoint, Node*& subList) {
	/*
	return nullptr if it matches
	return startingPoint if it fails so that something can continue on.
	*/
	cout << "Compare Two Function" << endl;
	print(startingPoint);
	print(subList);

	Node* cursorStartingPoint = startingPoint;
	Node* subListCursor = subList;

	while (cursorStartingPoint->data == subListCursor->data) {
		print(cursorStartingPoint);
		print(subListCursor);

		cursorStartingPoint = cursorStartingPoint->link;
		subListCursor = subListCursor->link;
		if (cursorStartingPoint == nullptr || subListCursor == nullptr) {
			break;
		}
	}

	if (cursorStartingPoint == nullptr && subList == nullptr) {
		return nullptr;
	}
	else {
		return cursorStartingPoint;
	}
}

Node* subList(Node* baseList, Node* subList) {
	cout << "=============SubList FUNCTION====================\n\n" << endl;
	if (baseList == nullptr || subList == nullptr) {
		cout << "Something was null" << endl;
		return nullptr;
	}
	cout << "BASE LIST" << endl;
	print(baseList);
	cout << "SUBLIST" << endl;
	print(subList);

	//Situation One
	Node* cursorBase = baseList;
	Node* cursorSub = subList;

	bool control = true;
	while (control) {
		//Find the first part 
		while (cursorBase->data != cursorSub->data) {
			cursorBase = cursorBase->link;
			/*End Case Scenario*/
			if (cursorBase->link == nullptr) {
				if (cursorBase->data != cursorSub->data) { //If the data doesn't match... 
					cout << "TEST FAILED END LIST" << endl;
					return nullptr;
				}
				if (cursorSub->link != nullptr) { //If it does match, but sub has a link then...
					cout << "TEST FAILED END LIST" << endl;
					return nullptr;
				}
				cout << "TESTS SUCCEEDED AT END LIST!" << endl;
				return cursorBase; //If both the condition above is false, it means that
								   //data matches and that sub only has a size of 1.
			}
		}

		/*
		Once Data Matches...
		Compare the Two results till the end.
		*/

		//If nullptr the result has been found...
		Node* result = compareTwo(cursorBase, cursorSub);
		if (result == nullptr) {
			cout << "TEST SUCCEEDED! FOUND SUBLIST!" << endl;
			return cursorBase;
		}
		//else
		cout << "TEST FAILED" << endl;
		cout << "Retrying... hasn't hit the end of the list...." << endl;
		cursorBase = cursorBase->link;
	}
}


Node* subListAddress(Node*& baseList, Node*& secondList) {
	if (baseList == nullptr || secondList == nullptr) {
		cout << "Something was null" << endl;
		return nullptr;
	}
	Node* cursorsecondList = secondList;
	Node* cursorbaseList = baseList;

	while (cursorbaseList != nullptr) {
		while (cursorsecondList != baseList && cursorsecondList != nullptr) {
			cursorsecondList = cursorsecondList->link;
		}
		if (cursorsecondList == baseList) {
			cout << "True";
			return cursorsecondList;
		}
		else {
			cout << "False";
			return nullptr;
		}
		cursorbaseList = cursorbaseList->link;
	}
}

int main() {
	vector <int> testList;
	testList.push_back(7);
	testList.push_back(2);
	testList.push_back(2);
	testList.push_back(7);
	testList.push_back(2);
	testList.push_back(3);
	Node* tempHold = listBuild(testList);

	vector <int> base;
	base.push_back(7);
	base.push_back(2);
	base.push_back(3);

	Node* baseNode = listBuild(base);

	splice(tempHold, baseNode);
	subList(baseNode, tempHold);

	listClear(baseNode);
	listClear(tempHold);
	listClear(baseNode);
}
