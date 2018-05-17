/*
Justin Lin
NYU ID: jwl488
N#: 19699912
Name File: lec12
Purpose:
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

//class Node {
//public:
//private:
//	int data;
//};
//
//Node* listDup(Node* p) {
//	if (p == nullptr) return nullptr;
//	//Node* result = listDup(p->next);
//	return new Node(p->data, listDup(p->next)); //recursive loop
//}

void towers(int n, char start, char target, char spare) {
	//if (n == 1) {
	//	cout << "Move disk: " << n << " from spindle: " << start << " to spindle: " << target; 
	//}
	if (n == 0) {
		return;
	}
	else {
		towers(n -1, start, spare, target);
		cout << "Move disk: " << n << " from spindle: " << start << " to spindle:	" << target << endl;
		towers(n - 1, spare, target, start);
	}
}

int fib(int n) {
	if (n <= 2) return 1;
	return fib(n - 1) + fib(n - 2);
}

void printDigitsR(int n) {
	if (n < 10) {
		cout << n << endl;
		return;
	}
	cout << n % 10 << ' ';
	printDigitsR(n / 10);
}

void printBits(int n) {
	if (n < 2) {
		cout << n << ' ';
		return;
	}
	else{
		printBits(n / 2);
		cout << n % 2 << ' ';
	}
}

/*
//Recursion for Sum of Binary Tree
int treeSum(TNode* root){
//if (root == nullptr) return 0; //Only if all values are greater than 0
	//if we don't assume all values greater than 0 tho...

	int result = root->value;
	if(root->left) result += (treeSum(root->left);
	if(root->right) result += treeSum(root->right);
	return result;
}


/*
Main Function
*/
int main() {
	towers(3, 'A', 'B', 'C');
	//cout << fib(10) << endl;

	printDigitsR(3150409);
	cout << endl;
	printBits(10);
}

/*/
Functions
*/
