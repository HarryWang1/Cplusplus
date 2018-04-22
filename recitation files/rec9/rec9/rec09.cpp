/*
Name: Justin Lin
Purpose: Practice Inheritance

*/


////Task 2
//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//protected:
//private:
//	unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//protected:
//private:
//	unsigned numOfPages;
//};
//
//class Book : public PrintedMaterial {
//public:
//protected:
//private:
//	unsigned numOfPages;
//};
//
//class TextBook : public Book {
//public:
//protected:
//private:
//	unsigned numOfPages;
//};
//
//class Novel : public Book {
//public:
//protected:
//private:
//	unsigned numOfPages;
//};
//
//// tester/modeler code
//int main()
//{
//	TextBook t;
//	Novel n;
//	Magazine m;
//}
//
////Task 3
//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//protected:
//private:
//	unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//protected:
//private:
//};
//
//class Novel : public Book {
//public:
//protected:
//private:
//};
//
//// tester/modeler code
//int main()
//{
//	TextBook t;
//	Novel n;
//	Magazine m;
//}
//
////Task 4
//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//	PrintedMaterial(unsigned numPages): numOfPages(numPages){}
//protected:
//private:
//	unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//protected:
//private:
//};
//
//class Novel : public Book {
//public:
//protected:
//private:
//};
//
//// tester/modeler code
//int main()
//{
//	TextBook t;
//	Novel n;
//	Magazine m;
//}

////Task 5
//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//	PrintedMaterial(unsigned numPages)
//		: numOfPages(numPages)
//	{}
//protected:
//private:
//	unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//	Magazine(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//	Book(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//	TextBook(unsigned numPages)
//		: Book(numPages)
//	{}
//protected:
//private:
//};
//
//class Novel : public Book {
//public:
//	Novel(unsigned numPages)
//		: Book(numPages)
//	{}
//protected:
//private:
//};
//
//// tester/modeler code
//int main()
//{
//	TextBook t(5430);
//	Novel n(213);
//	Magazine m(6);
//}

////Task 6
//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//	PrintedMaterial(unsigned numPages)
//		: numOfPages(numPages)
//	{}
//
//	void displayNumPages() const { cout << numOfPages; }	
//protected:
//private:
//	unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//	Magazine(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//	Book(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//	TextBook(unsigned numPages)
//		: Book(numPages)
//	{}
//protected:
//private:
//};
//
//class Novel : public Book {
//public:
//	Novel(unsigned numPages)
//		: Book(numPages)
//	{}
//protected:
//private:
//};
//
//// tester/modeler code
//int main()
//{
//	TextBook t(5430);
//	Novel n(213);
//	Magazine m(6);
//}

//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//	PrintedMaterial(unsigned numPages)
//		: numOfPages(numPages)
//	{}
//	void displayNumPages() const
//	{
//		cout << numOfPages;
//	}
//protected:
//	unsigned numOfPages;
//private:
//	
//};
//
//class Magazine : public PrintedMaterial {
//public:
//	Magazine(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//	Book(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//	TextBook(unsigned numPages, unsigned numIndxPgs)
//		: Book(numPages),
//		numOfIndexPages(numIndxPgs)
//	{}
//	void displayNumPages() const
//	{
//		cout << numOfIndexPages << endl;
//		cout << numOfPages;
//	}
//protected:
//	
//private:
//	unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//	Novel(unsigned numPages)
//		: Book(numPages)
//	{}
//protected:
//private:
//};
//
//// tester/modeler code
//int main()
//{
//	TextBook t(5430, 234);
//	Novel n(213);
//	Magazine m(6);
//
//	t.displayNumPages();
//	n.displayNumPages();
//	m.displayNumPages();
//}

////Task 8
//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//	PrintedMaterial(unsigned numPages)
//		: numOfPages(numPages)
//	{}
//	void displayNumPages() const
//	{
//		cout << numOfPages << endl;
//	}
//protected:
//private:
//	unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//	Magazine(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//	Book(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//	TextBook(unsigned numPages, unsigned numIndxPgs)
//		: Book(numPages),
//		numOfIndexPages(numIndxPgs)
//	{}
//	void displayNumPages() const
//	{
//		cout << "Pages: ";
//		PrintedMaterial::displayNumPages();
//		cout << "Index pages: ";
//		cout << numOfIndexPages << endl;
//	}
//protected:
//private:
//	unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//	Novel(unsigned numPages)
//		: Book(numPages)
//	{}
//protected:
//private:
//};
//
//// tester/modeler code
//int main()
//{
//	TextBook t(5430, 23);
//	Novel n(213);
//	Magazine m(6);
//
//	t.displayNumPages();
//	n.displayNumPages();
//	m.displayNumPages();
//
//}

////Task9 

//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//	PrintedMaterial(unsigned numPages)
//		: numOfPages(numPages)
//	{}
//	void displayNumPages() const
//	{
//		cout << numOfPages << endl;
//	}
//protected:
//private:
//	unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//	Magazine(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//	Book(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//	TextBook(unsigned numPages, unsigned numIndxPgs)
//		: Book(numPages),
//		numOfIndexPages(numIndxPgs)
//	{}
//	void displayNumPages() const
//	{
//		cout << "Pages: ";
//		PrintedMaterial::displayNumPages();
//		cout << "Index pages: ";
//		cout << numOfIndexPages << endl;
//	}
//protected:
//private:
//	unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//	Novel(unsigned numPages)
//		: Book(numPages)
//	{}
//protected:
//private:
//};
//
//// tester/modeler code
//int main()
//{
//	TextBook t(5430, 23);
//	Novel n(213);
//	Magazine m(6);
//
//	t.displayNumPages();
//	n.displayNumPages();
//	m.displayNumPages();
//
//	cout << "\nA PrintedMaterial material object!\n";
//	PrintedMaterial pm(2345);
//	pm.displayNumPages();
//
//	cout << "\nA PrintedMaterial variable containing a TextBook value\n";
//	pm = t; //slicing error
//	pm.displayNumPages();
//
//}

////Task 10
//
//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//	PrintedMaterial(unsigned numPages)
//		: numOfPages(numPages)
//	{}
//	void displayNumPages() const
//	{
//		cout << numOfPages << endl;
//	}
//protected:
//private:
//	unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//	Magazine(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//	Book(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//	TextBook(unsigned numPages, unsigned numIndxPgs)
//		: Book(numPages),
//		numOfIndexPages(numIndxPgs)
//	{}
//	void displayNumPages() const
//	{
//		cout << "Pages: ";
//		PrintedMaterial::displayNumPages();
//		cout << "Index pages: ";
//		cout << numOfIndexPages << endl;
//	}
//protected:
//private:
//	unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//	Novel(unsigned numPages)
//		: Book(numPages)
//	{}
//protected:
//private:
//};
//
//// tester/modeler code
//int main()
//{
//	TextBook t(5430, 23);
//	Novel n(213);
//	Magazine m(6);
//
//	t.displayNumPages();
//	n.displayNumPages();
//	m.displayNumPages();
//
//	cout << "\nA PrintedMaterial material object!\n";
//	PrintedMaterial pm(2345);
//	pm.displayNumPages();
//
//	cout << "\nA PrintedMaterial variable containing a TextBook value\n";
//	pm = t; // like putting a t into a vector of PrintedMaterials
//	pm.displayNumPages();
//
//	cout << "Try using pointer to base type\n";
//PrintedMaterial* pmPtr;
//pmPtr = &t;
// instead of putting an actual PrintedMaterial
// object into the vector, we put a pointer to
// a PrintedMaterial object (t) into a vector
// of pointers-to-PrintedMaterial
// (that is, pointers to the Base class)
// we'll be "managing" our objects by using
// pointers to PrintedMaterial values.
//
//	pmPtr->displayNumPages();
//}


////Task 11
//
//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//	PrintedMaterial(unsigned numPages)
//		: numOfPages(numPages)
//	{}
//	virtual void displayNumPages() const
//	{
//		cout << numOfPages << endl;
//	}
//protected:
//private:
//	unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//	Magazine(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//	Book(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//	TextBook(unsigned numPages, unsigned numIndxPgs)
//		: Book(numPages),
//		numOfIndexPages(numIndxPgs)
//	{}
//	void displayNumPages() const
//	{
//		cout << "Pages: ";
//		PrintedMaterial::displayNumPages();
//		cout << "Index pages: ";
//		cout << numOfIndexPages << endl;
//	}
//protected:
//private:
//	unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//	Novel(unsigned numPages)
//		: Book(numPages)
//	{}
//protected:
//private:
//};
//
//// tester/modeler code
//int main()
//{
//	TextBook t(5430, 23);
//	Novel n(213);
//	Magazine m(6);
//
//	t.displayNumPages();
//	n.displayNumPages();
//	m.displayNumPages();
//
//	cout << "\nA PrintedMaterial material object!\n";
//	PrintedMaterial pm(2345);
//	pm.displayNumPages();
//
//	cout << "\nA PrintedMaterial variable containing a TextBook value\n";
//	pm = t; // like putting a t into a vector of PrintedMaterials
//	pm.displayNumPages();
//
//	cout << "Try using pointer to base type\n";
//PrintedMaterial* pmPtr;
//pmPtr = &t;
// instead of putting an actual PrintedMaterial
// object into the vector, we put a pointer to
// a PrintedMaterial object (t) into a vector
// of pointers-to-PrintedMaterial
// (that is, pointers to the Base class)
// we'll be "managing" our objects by using
// pointers to PrintedMaterial values.
//
//	pmPtr->displayNumPages();
//}
//
//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//	PrintedMaterial(unsigned numPages)
//		: numOfPages(numPages)
//	{}
//	virtual
//		void displayNumPages() const
//	{
//		cout << numOfPages << endl;
//	}
//protected:
//private:
//	unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//	Magazine(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//	Book(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//	TextBook(unsigned numPages, unsigned numIndxPgs)
//		: Book(numPages),
//		numOfIndexPages(numIndxPgs)
//	{}
//	void displayNumPages() const
//	{
//		cout << "Pages: ";
//		PrintedMaterial::displayNumPages();
//		cout << "Index pages: ";
//		cout << numOfIndexPages << endl;
//	}
//protected:
//private:
//	unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//	Novel(unsigned numPages)
//		: Book(numPages)
//	{}
//protected:
//private:
//};
//
//
//void displayNumberOfPages(const PrintedMaterial& anyPM)
//{
//	anyPM.displayNumPages();
//}
//
//
//// tester/modeler code
//int main()
//{
//	TextBook t(5430, 23);
//	Novel n(213);
//	Magazine m(6);
//
//	t.displayNumPages();
//	n.displayNumPages();
//	m.displayNumPages();
//
//	cout << "\nA PrintedMaterial material object!\n";
//	PrintedMaterial pm(2345);
//	pm.displayNumPages();
//
//	pm = t; // like putting a t into a vector of PrintedMaterials
//	pm.displayNumPages();
//
//	cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
//	cout << "Now with the virtual mechanism involved\n";
//	// should work now that the virtual mechanism is being invoked
//	PrintedMaterial* pmPtr;
//	pmPtr = &t; 
//	pmPtr->displayNumPages();
//
//	// print some stuff by calling a generic function
//	cout << "\nUse a generic functino for printing\n";
//	displayNumberOfPages(m);
//	displayNumberOfPages(n);
//	displayNumberOfPages(t);
//
//}

////Task 13

/*
Won't compile b/c the abstract class hasn't been override.
*/


//#include <iostream>
//using namespace std;
//
//class PrintedMaterial {
//public:
//	PrintedMaterial(unsigned numPages)
//		: numOfPages(numPages)
//	{}
//
//	//               LOOK AT THE = 0
//	virtual void displayNumPages() const = 0;
//private:
//	unsigned numOfPages;
//};
//
//void PrintedMaterial::displayNumPages() const {
//	cout << numOfPages << endl;
//}
//
//class Magazine : public PrintedMaterial {
//public:
//	Magazine(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//};
//
//class Book : public PrintedMaterial {
//public:
//	Book(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//};
//
//class TextBook : public Book {
//public:
//	TextBook(unsigned numPages, unsigned numIndxPgs)
//		: Book(numPages),
//		numOfIndexPages(numIndxPgs)
//	{}
//	void displayNumPages() const {
//		cout << "Pages: ";
//		PrintedMaterial::displayNumPages();
//		cout << "Index pages: ";
//		cout << numOfIndexPages << endl;
//	}
//private:
//	unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//	Novel(unsigned numPages)
//		: Book(numPages)
//	{}
//};
//
//
//// note that reference to PrintedMaterial is the parameter type
//// now we can use the dot member operator
//// if use the -> operator, thats not going to work (try it!)
//void displayNumberOfPages(const PrintedMaterial& anyPM) {
//	anyPM.displayNumPages();
//}
//
//
//// tester/modeler code
//int main() {
//	TextBook t(5430, 23);
//	Novel n(213);
//	Magazine m(6);
//
//	t.displayNumPages();
//	n.displayNumPages();
//	m.displayNumPages();
//
//	cout << "\nA PrintedMaterial material object!\n";
//	PrintedMaterial pm(2345);
//	pm.displayNumPages();
//
//	pm = t; // like putting a t into a vector of PrintedMaterials
//	pm.displayNumPages();
//
//	cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
//	cout << "Now with the virtual mechanism involved\n";
//	// should work now that the virtual mechanism is being invoked
//	PrintedMaterial* pmPtr;
//	pmPtr = &t; // like putting t into a vector but
//				// we are actually putting the address of t
//				// into a vector pointers of pointers to
//				// PrintedMaterials. We'll "say" we are putting
//	pmPtr->displayNumPages();
//
//	// print some stuff by calling a generic function
//	cout << "\nUse a generic functino for printing\n";
//	displayNumberOfPages(m);
//	displayNumberOfPages(n);
//	displayNumberOfPages(t);
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class PrintedMaterial {
//public:
//	PrintedMaterial(unsigned numPages)
//		: numOfPages(numPages)
//	{}
//
//	virtual void displayNumPages() const = 0;
//
//protected:
//private:
//	unsigned numOfPages;
//};
//
//void PrintedMaterial::displayNumPages() const {
//	cout << numOfPages << endl;
//}
//
//class Magazine : public PrintedMaterial {
//public:
//	Magazine(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//
//	// virtual - NOTE even without writing "virtual"
//	// again, this overriden method IS virtual
//	// viruality cannot be removed once installed
//	// Also note that the = 0 has is not there
//	void displayNumPages() const
//	{
//		cout << "Hi, I'm a Magazine object stored\n"
//			<< "(but I can't know that I am being\n"
//			<< "stored (by pointer) in a vector of\n"
//			<< "PrintedMaterial pointers!\n";
//		PrintedMaterial::displayNumPages();
//		cout << "(and I'm very glossy!\n";
//	}
//
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//	Book(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//	TextBook(unsigned numPages, unsigned numIndxPgs)
//		: Book(numPages),
//		numOfIndexPages(numIndxPgs)
//	{}
//
//	void displayNumPages() const
//	{
//		cout << "\nThis is a textbook.\n";
//		cout << "It is a very boring textbook.\n";
//		cout << "Pages: ";
//		PrintedMaterial::displayNumPages();
//		cout << "Index pages: ";
//		cout << numOfIndexPages << endl;
//	}
//protected:
//private:
//	unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//	Novel(unsigned numPages)
//		: Book(numPages)
//	{}
//	void displayNumPages() const
//	{
//		cout << "\nThis is the story of a very\n"
//			<< " interesting programmer's quest\n"
//			<< "  understand inheritance.\n"
//			<< "   The journey is just beginning\n"
//			<< "    and already the journeyman\n"
//			<< "      hacker, no - not a hacker! -\n"
//			<< "         a programmer who reads, and\n"
//			<< "             studies and understands code\n"
//			<< "                 Hackers steal and don't even\n"
//			<< "                      try to understand what they stole\n"
//			<< "                           before using it.\n"
//			<< "\n       ...But I digress.\n"
//			<< "\nThis novel is quite long, there\n"
//			<< "being this number of pages:\n"
//			<< "=====================================\n"
//			<< "                 ";
//		PrintedMaterial::displayNumPages();
//		cout << "=====================================\n"
//			<< "Whew!\n"
//			<< " but there is an exciting\n"
//			<< "  programming adventure on every\n"
//			<< "   single one of them!\n"
//			<< "    And now, let's let the quest continue..."
//			<< endl << endl << endl;
//	}
//protected:
//private:
//};
//
//
//// tester/modeler code
//int main()
//{
//	TextBook t(5430, 23);
//	Novel n(213);
//	Magazine m(6);
//
//	t.displayNumPages();
//	n.displayNumPages();
//	m.displayNumPages();
//
//	cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
//	cout << "Now with the virtual mechanism involved\n";
//	PrintedMaterial* pmPtr;
//	pmPtr = &t; // like putting t into a vector but
//				// we are actually putting the address of t
//				// into a vector pointers of pointers to
//				// PrintedMaterials. We'll "say" we are putting
//				// t into the vector
//				// (that is, pointers to the Base class)
//	pmPtr->displayNumPages();
//
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class PrintedMaterial {
//public:
//	PrintedMaterial(unsigned numPages)
//		: numOfPages(numPages)
//	{}
//
//	virtual
//		void displayNumPages() const = 0;
//private:
//	unsigned numOfPages;
//};
//
//void PrintedMaterial::displayNumPages() const {
//	cout << numOfPages << endl;
//}
//
//class Magazine : public PrintedMaterial {
//public:
//	Magazine(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//
//	// virtual NOTE even without writing "virtual"
//	// again, this overriden method IS virtual
//	// viruality cannot be removed once installed
//	// Also note that the = 0 has is not there
//	void displayNumPages() const
//	{
//		cout << "Hi, I'm a Magazine object stored\n"
//			<< "(but I can't know that I am being\n"
//			<< "stored (by pointer) in a vector of\n"
//			<< "PrintedMaterial pointers!\n";
//		PrintedMaterial::displayNumPages();
//		cout << "(and I'm very glossy!\n";
//	}
//
//protected:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//	Book(unsigned numPages)
//		: PrintedMaterial(numPages)
//	{}
//protected:
//private:
//};
//
//class TextBook : public Book {
//public:
//	TextBook(unsigned numPages, unsigned numIndxPgs)
//		: Book(numPages),
//		numOfIndexPages(numIndxPgs)
//	{}
//
//	void displayNumPages() const
//	{
//		cout << "\nThis is a textbook.\n";
//		cout << "It is a very boring textbook.\n";
//		cout << "Pages: ";
//		PrintedMaterial::displayNumPages();
//		cout << "Index pages: ";
//		cout << numOfIndexPages << endl;
//	}
//protected:
//private:
//	unsigned numOfIndexPages;
//};
//
//class Novel : public Book {
//public:
//	Novel(unsigned numPages)
//		: Book(numPages)
//	{}
//	void displayNumPages() const
//	{
//		cout << "\nThis is the story of a very\n"
//			<< " interesting programmer's quest\n"
//			<< "  understand inheritance.\n"
//			<< "   The journey is just beginning\n"
//			<< "    and already the journeyman\n"
//			<< "      hacker, no - not a hacker! -\n"
//			<< "         a programmer who reads, and\n"
//			<< "             studies and understands code\n"
//			<< "                 Hackers steal and don't even\n"
//			<< "                      try to understand what they stole\n"
//			<< "                           before using it.\n"
//			<< "\n       ...But I digress.\n"
//			<< "\nThis novel is quite long, there\n"
//			<< "being this number of pages:\n"
//			<< "=====================================\n"
//			<< "                 ";
//		PrintedMaterial::displayNumPages();
//		cout << "=====================================\n"
//			<< "Whew!\n"
//			<< " but there is an exciting\n"
//			<< "  programming adventure on every\n"
//			<< "   single one of them!\n"
//			<< "    And now, let's let the quest continue..."
//			<< endl << endl << endl;
//	}
//protected:
//private:
//};
//
//
//// tester/modeler code
//int main()
//{
//	TextBook t(5430, 23);
//	Novel n(213);
//	Magazine m(6);
//
//	// as direct method calls
//	cout << "\nEach will now be asked directly,\n"
//		<< "using the dot member operator to\n"
//		<< "display its number of pages:\n";
//	t.displayNumPages();
//	n.displayNumPages();
//	m.displayNumPages();
//
//	// Storing generic objects in a vector 
//	cout << "\n\nNow we'll use a container. Yea!!!\n\n";
//	vector< PrintedMaterial* > materials;
//	materials.push_back(&t);
//	materials.push_back(&n);
//	materials.push_back(&m);
//	for (size_t i = 0; i < materials.size(); ++i)
//	{
//		materials[i]->displayNumPages();
//		cout << endl;
//	}
//}
