/*
Very simple:
	Read a file
	Take the data
	add the data of each line onto the heap and into a vector

	Next Method:
	Go through vector
	delete each pointer
	clear the vector after the loop
*/
#include<vector>
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

struct Thing{
	string word;
	int integer;
};

void fill( ifstream& ifs, vector<Thing*>& listOfThings ){
	string word;
	int integer;
	//We could use "readline" but this is easier for me to understand
		//We start with the name of the ifstream and then the different string characters
		//that are seperated by whitespace.
	while( ifs >> word >> integer ){
		//Create a new object on the vector
			//Struct, so we need to assign the values seperately
			//You could also make a "class" and then a constructor, writing this code:
				//Thing* heapThing = new Thing( word, integer );
				//This would clear up three lines of code into 1
		Thing* heapThing = new Thing;
		heapThing->word = word;
		heapThing->integer = integer;
		//Now that all the values to the heapThing have been assigned we push it onto the vector
		listOfThings.push_back( heapThing );
	}
}

void release( vector<Thing*>& listOfThings ){
	for( size_t i = 0; i < listOfThings.size(); ++i ){
		//This will free up memory on the heap so that we don't have any memore leaks
		//when the vector is cleared
		delete listOfThings[i];
	}
	//We clear the vector so that we don't have an "dangling pointers"
		//Dangling pointer: a pointer that points to something that doesn't exist
	listOfThings.clear();
}
int main(){
	//To test and see what this code does, I suggest using the debugger with a red
	//dot on line.... 61 (where fill is called in main()
	ifstream ifs("things.txt");
	vector<Thing*> things;
	fill(ifs, things);
	release(things);
}
