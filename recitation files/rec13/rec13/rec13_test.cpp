// rec13_test.cpp
/*
Justin Lin
Rec 13

*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <set>         // task 20
#include <map>         // task 22
using namespace std;


/*
Task 9
*/
void printList(list<int>& task2) {//cannot pass in by const b/c will not work...
	list<int>::iterator j;
	for (j = task2.begin(); j != task2.end(); ++j) {
		cout << *j << " ";
	}
}

void printList2(const list<int>& task2) { //here you do past in by const you need to make sure the iterator type matches
	list<int>::const_iterator j;
	for (j = task2.begin(); j != task2.end(); ++j) {
		cout << *j << " ";
	}
}


//Task 10
void printList3(const list<int>& task2) {
	for (const int& i : task2) { cout << i << " "; }
}

/*
Task 12
*/

list<int>::const_iterator findList(const list<int>& task2, int target) {//cannot pass in by const b/c will not work...
	list<int>::const_iterator j;
	for (j = task2.begin(); j != task2.end(); ++j) {
		if (*j == target) {
			return j;//if target is found
		}
	}
	return task2.end(); //if you don't find it
}

auto findList2(const list<int>& task2, int target) {//cannot pass in by const b/c will not work...
	for (auto j = task2.begin(); j != task2.end(); ++j) {
		if (*j == target) {
			return j;//if target is found
		}
	}
	return task2.end(); //if you don't find it
}

/*
Task 15
*/
bool IsEven(int i) {
	return ((i % 2) == 0);
}

/*
Task 16
*/
class functor {
public:
	functor(int n) : n(n) {}

	bool operator() (int k) {
		return k % n == 0;
	}
private:
	int n;
};

/*
Task 19
*/

list<int>::iterator ourFind(const list<int>::iterator& begin, const list<int>::iterator& end, int target) {
	list<int>::iterator j;
	for (j = begin; j != end; ++j) {
		if (*j == target) {
			cout << "Target Found" << endl;
			return j;//if target is found
		}
	}
	cout << "Target not found" << endl;
	return end;
}

/*
Task 20
*/
template<class It, class T>
It ourFind2(It& begin, const It& end, const T& target)
{
	while (begin != end) {
		if (*begin == target) return begin;
		++begin;
	}
	return end;
}

int main() {
	// 1. Create a vector with some values and display using ranged for
	cout << "Task 1:\n";

	vector<int>task1;
	for (size_t i = 0; i < 10; ++i) {
		int v1 = rand() % 100;
		task1.push_back(v1);
	}

	for (int i : task1) { cout << i << " "; }
	cout << endl;

	cout << "\n=======\n";

	// 2. Initalize a list as a copy of values from the vector
	cout << "Task 2:\n";
	list<int> task2;
	for (int i : task1) { task2.push_back(i); }
	for (int& i : task2) { cout << i << " "; }
	cout << "\n=======\n";

	// 3. Sort the original vector.  Display both the vector and the list
	cout << "Task 3:\n";
	sort(task1.begin(), task1.end());
	cout << "Sorted Task 1" << endl;
	for (int i : task1) { cout << i << " "; }

	cout << "\n=======\n";

	// 4. print every other element of the vector.
	cout << "Task 4:\n";
	for (size_t i = 0; i < task1.size(); i += 2) {
		cout << task1[i] << " ";
	}
	cout << endl;
	cout << "\n=======\n";

	// 5. Attempt to print every other element of the list using the
	//    same technique.
	cout << "Task 5:\n";
	list<int>::iterator i;
	for (i = task2.begin(); i != task2.end();) {
		cout << *i << " ";
		++i;
		++i;
	}
	cout << endl;
	cout << "\n=======\n";

	//
	// Iterators
	//

	// 6. Repeat task 4 using iterators.  Do not use auto;
	cout << "Task 6:\n";
	for (vector<int>::iterator it = task1.begin(); it != task1.end(); ++ ++it) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "\n=======\n";

	// 7. Repeat the previous task using the list.  Again, do not use auto.
	//    Note that you cannot use the same simple mechanism to bump
	//    the iterator as in task 6.
	cout << "Task 7:\n";
	list<int>::iterator j;
	for (j = task2.begin(); j != task2.end();) {
		cout << *j << " ";
		++j;
		++j;
	}
	cout << endl;
	cout << "\n=======\n";

	// 8. Sorting a list
	cout << "Task 8:\n";
	task2.sort();
	list<int>::iterator p;
	for (p = task2.begin(); p != task2.end(); ++p) {
		cout << *p << " ";
	}
	cout << "\n=======\n";

	// 9. Calling the function to print the list
	cout << "Task 9:\n";
	printList(task2); //non const
	cout << endl;
	printList2(task2); //const
	cout << "\n=======\n";

	// 10. Calling the function that prints the list, using ranged-for
	cout << "Task 10:\n";
	printList3(task2);//const forloop
	cout << "=======\n";

	//
	// Auto
	//

	// 11. Calling the function that, using auto, prints alterate
	// items in the list
	cout << "Task 11:\n";
	for (auto task11Var = task2.begin(); task11Var != task2.end();) {
		cout << *task11Var << " ";
		++task11Var;
		++task11Var;
	}

	cout << "\n=======\n";


	// 12.  Write a function find that takes a list and value to search for.
	//      What should we return if not found
	cout << "Task 12:\n";
	int target = 0;
	findList(task2, target);

	cout << "\n=======\n";

	// 13.  Write a function find that takes a list and value to search for.
	//      What should we return if not found
	cout << "Task 13:\n";
	target = 0;
	findList2(task2, target);
	cout << "\n=======\n";

	//
	// Generic Algorithms
	//

	// 14. Generic algorithms: find
	cout << "Task 14:\n";
	target = 0;
	p = find(task2.begin(), task2.end(), target);
	if (p != task2.end())
		std::cout << "Element found in myints: " << *p << '\n';
	else
		std::cout << "Element not found in myints\n";
	cout << "=======\n";

	// 15. Generic algorithms: find_if
	cout << "Task 15:\n";

	std::vector<int>::iterator it = std::find_if(task1.begin(), task1.end(), IsEven);
	std::cout << "The first even value is " << *it << '\n';

	cout << "\n=======\n";

	// 16. Functor
	cout << "Task 16:\n";
	/*
	Look above the main function and go to the appropriate comment saying Task 16.
	*/

	cout << "Look above the main function and go to the appropriate comment saying Task 16." << endl;
	cout << "\n=======\n";

	// 17. Lambda
	cout << "Task 17:\n";
	[] { cout << "Hello Lambda!"; }();

	[](int a, int b) { cout << a << " " << b; }(1, 2);

	int result = [](int a, int b) { return a + b; } (4, 5);
	cout << "the result is: " << result << endl;

	int result2 = [](int a, int b) -> int { return a + b; } (4, 5);
	cout << "the result is: " << result2 << endl;

	cout << "\n=======\n";

	// 18. Generic algorithms: copy to an array
	cout << "Task 18:\n";
	int arr[100];
	copy(task2.begin(), task2.end(), arr);

	cout << "\n=======\n";

	//
	// Templated Functions
	//

	// 19. Implement find as a function for lists
	cout << "Task 19:\n";
	cout << "OurFind Function: " << *ourFind(task2.begin(), task2.end(), target) << endl;
	cout << "\n=======\n";

	// 20. Implement find as a templated function
	cout << "Task 20:\n";
	cout << "OurFind2 Template Function Using List: " << *ourFind2(task2.begin(), task2.end(), target) << endl;
	cout << "OurFind2 Template Function Using Vector: " << *ourFind2(task1.begin(), task1.end(), target) << endl;

	cout << "\n=======\n";

	//
	// Associative collections
	//

	// 21. Using a vector of strings, print a line showing 
	cout << "Task 21:\n";
	string word;
	vector<string>textFile;
	ifstream infile("pooh-nopunc.txt");
	while (infile >> word)
	{
		bool inVector = std::find(textFile.begin(), textFile.end(), word) != textFile.end();
		//return true if in vector

		if (!inVector) {
			textFile.push_back(word);
		}
	}

	infile.close();
	cout << "Size of Vector: " << textFile.size() << endl;
	cout << "Unique Words in the File" << endl;
	for (const string& word : textFile) {
		cout << word << " ";
	}

	cout << "\n=======\n";

	// 22. Repeating previous step, but using the set
	cout << "Task 22:\n";
	set<string> setWords;

	ifstream infile2("pooh-nopunc.txt");
	while (infile2 >> word)
	{
		setWords.insert(word);
	}

	for (auto j = setWords.begin(); j != setWords.end(); ++j) {
		cout << *j << " ";
	}

	infile.close();
	cout << "\n=======\n";

	// 23. Word co-occurence using map
	cout << "Task 23:\n";
	map<string, vector<int>> wordMap;
	int index = 0;
	ifstream infile3("pooh-nopunc.txt");
	while (infile3 >> word)
	{
		wordMap[word].push_back(index);
		++index;
	}
	for (const auto& pair : wordMap) {
		cout << "< " << pair.first << " : ";
		for (int index : pair.second) {
			cout << index << ", ";
		}
		cout << " >";
	}

	cout << "\n=======\n";
}
