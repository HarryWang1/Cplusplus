//Write an assignment operator
//Assume Class Thing has a deconstructor and copy constructor
//Write an assignment operator for GotHeap

//Short Answer Question

class Thing{
public: 
	Thing(string s) : s(s) {}
	// some other methods
private:
	string s;

};

class GotHeap {
public:
	GotHeap(string s) : p(new Thing(s)) {}
	~GetHeap() {delete p;}
private:
	Thing *p;
};