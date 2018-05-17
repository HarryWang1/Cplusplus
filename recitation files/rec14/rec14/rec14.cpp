/*
Justin Lin
Rec 14

*/
#include <iostream>
using namespace std;

struct TNode {
	TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
		: data(data), left(left), right(right) {}
	int data;
	TNode *left, *right;
};

struct Node {
	Node(int data = 0, Node *right = nullptr)
		: data(data), right(right) {}
	int data;
	Node *right;
};

struct nullPtrException : public exception {};

int towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
	if (n == 1) { return 1; }
	int answer = 1;
	answer += towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
	answer += towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int max(TNode* root) {
	// Base case
	if (root == nullptr)
		throw nullPtrException();

	int baseRes = root->data;
	int leftres = 0;
	int rightres = 0;

	if (root->left != nullptr) { int leftRes = max(root->left); }
	else { leftres = 0; }

	if (root->right != nullptr) { int rightRes = max(root->right); }
	else { rightres = 0; }

	if (leftres > baseRes) baseRes = leftres;
	if (rightres > baseRes) baseRes = rightres;

	return baseRes;
}

bool palindrome(char *start, size_t len) { return len < 2 || (start[0] == start[len - 1] && palindrome(start + 1, len - 2)); }

bool printBits(int n) {
	if (n < 2) { return n; }
	else {
		bool ones = true; //0.
		if (printBits(n / 2)) { ones = !ones; }
		if (n % 2) { ones = !ones; }
		return ones;
	}
}

Node* recursiveSum(const Node* list1, const Node* list2) {
	if (list1 == nullptr && list2 == nullptr) { return nullptr; }
	if (list1 == nullptr) { return new Node(0 + list2->data); }
	if (list2 == nullptr) { return new Node(0 + list1->data); }
	return new Node(list1->data + list2->data, recursiveSum(list1->right, list2->right));
}

void mystery(int n) {
	if (n > 1) {
		cout << 'a';
		mystery(n / 2);
		cout << 'b';
		mystery(n / 2);
	}
	cout << 'c';
}

void printNode(Node* head) {
	Node* cursor = head;
	while (cursor->right != nullptr) {
		cout << cursor->data << " -> ";
		cursor = cursor->right;
	}
	cout << cursor->data;
	cout << endl;
}


int main() {
	cout << "Counting Even Bit" << endl;
	cout << "Even Bits: " << printBits(2) << endl;
	cout << "==================" << endl;

	Node* c = new Node(1);
	Node* b = new Node(2, c);
	Node* a = new Node(3, b);

	Node* dq = new Node(1);
	Node* cq = new Node(1, dq);
	Node* bq = new Node(2, cq);
	Node* aq = new Node(3, bq);

	cout << "Recursive Sum List: ";
	Node* answer = recursiveSum(a, aq);
	printNode(answer);
	cout << "==================" << endl;

	//Under b:
	TNode* dd = new TNode(6);
	TNode* ee = new TNode(5);

	//Under A
	TNode* cc = new TNode(100);
	TNode* bb = new TNode(5, dd, ee);
	TNode* aa = new TNode(1, bb, cc);

	try {
		cout << "Finding Max in Binary Tree: " << max(aa) << endl;
	}
	catch (nullPtrException& ex) {
		cout << "Root was Null" << endl;
	}
	catch (...) {
		cout << "Caught an unknown Exception" << endl;
	}

	TNode* aaa = nullptr;
	try {
		cout << "Finding Max in Binary Tree: " << max(aaa) << endl;
	}
	catch (nullPtrException& ex) {
		cout << "Root was Null" << endl;
	}
	catch (...) {
		cout << "Caught an unknown Exception" << endl;
	}

	cout << "==================" << endl;

	char arr[7] = { 'r', 'a', 'c', 'e', 'c', 'a','r' };
	cout << "Palindrome testing racecar: " << palindrome(arr, 7) << endl;
	cout << "==================" << endl;


	char arr1[7] = { 'n','o','o','n' };
	cout << "Palindrome testing noon: " << palindrome(arr1, 4) << endl;
	cout << "==================" << endl;

	for (size_t i = 1; i < 11; ++i) {
		cout << "towers(" << i << ",a, b, c): " << towerOfHanoi(i, 'A', 'C', 'B') << endl;
	}
	cout << "==================" << endl;

	for (size_t j = 1; j < 11; ++j) {
		mystery(j);
		cout << endl;
	}
	cout << "==================" << endl;

}