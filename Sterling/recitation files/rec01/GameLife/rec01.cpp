/*
rec01
Justin Lin
1.26.18

The Game of Life
/*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//Prints a 2D vector provided
void printGrid(vector <vector<char>>& grid) {
	for (size_t i = 0; i < grid.size(); ++i) {
		for (size_t k = 0; k < grid[i].size(); ++k) {
			if (grid[i][k] != '-') {
				cout << grid[i][k];
			}
			else {
				cout << ' ';
			}
		}
		cout << endl;
	}
}

//Initializes the grid from file
vector <vector<char>> initializingGrid(const string& file) {
	//ifStream
	ifstream ifsLine(file);
	if (!ifsLine) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	//Variable Initialization
	string line;
	int lineSize = 0; //Keeps track of linesize for border creation
	vector <vector<char>> grid; //Init master grid
	bool topBorder = true; //Calculate first time when init top border
	vector <char> topAndbottom; //Saves the top border for later use
	//Initializing the 2D Vector


	while (getline(ifsLine, line)) {
		lineSize = line.size();
		vector<char> tmpVec;
		if (topBorder) {
			//PUSHES BORDER ROW
			for (int initTop = 0; initTop <= lineSize + 1; ++initTop) {
				tmpVec.push_back('B');
			}
			topBorder = false;
			topAndbottom = tmpVec;
			grid.push_back(topAndbottom);

			//PUSHES IN THE LINE ALREADY IN THE IFSTREAM FROM GETLINE
			tmpVec.clear();
			tmpVec.push_back('B');
			for (char& c : line) {
				tmpVec.push_back(c);
			}
			tmpVec.push_back('B');
			grid.push_back(tmpVec);
		}
		//FILLS IN THE REST OF THE LINE
		else {
			tmpVec.push_back('B');
			for (char& c : line) {
				tmpVec.push_back(c);
			}
			tmpVec.push_back('B');
			grid.push_back(tmpVec);
		}
	}
	//ADDS IN A BOTTOM BORDER
	grid.push_back(topAndbottom);
	//printGrid(grid);
	return grid;
}

//CACULATES THE STATES FOR CELLS THAT ARE DEAD
bool deadStateTally(int row, int col, const vector <vector<char>>& grid) {
	int neighbor = 0;

	//Up down from center
	if (grid[row + 1][col] == '*') ++neighbor;
	if (grid[row - 1][col] == '*') ++neighbor;

	//Left Right from Center
	if (grid[row][col + 1] == '*') ++neighbor;
	if (grid[row][col - 1] == '*') ++neighbor;

	//Diagnals
	if (grid[row + 1][col + 1] == '*') ++neighbor;
	if (grid[row + 1][col - 1] == '*') ++neighbor;

	if (grid[row - 1][col + 1] == '*') ++neighbor;
	if (grid[row - 1][col - 1] == '*') ++neighbor;

	if (neighbor == 3) {
		return true;
	}
	else {
		return false;
	}
}

//CALCULATES THE STATE FOR WHEN CELLS ARE ALIVE
bool aliveStateTally(int row, int col, const vector <vector<char>>& grid) {
	int neighbor = 0;

	//Up down from center
	if (grid[row + 1][col] == '*') ++neighbor;
	if (grid[row - 1][col] == '*') ++neighbor;

	//Left Right from Center
	if (grid[row][col + 1] == '*') ++neighbor;
	if (grid[row][col - 1] == '*') ++neighbor;

	//Diagnals
	if (grid[row + 1][col + 1] == '*') ++neighbor;
	if (grid[row + 1][col - 1] == '*') ++neighbor;

	if (grid[row - 1][col + 1] == '*') ++neighbor;
	if (grid[row - 1][col - 1] == '*') ++neighbor;

	if (neighbor == 2 || neighbor == 3) {
		return true;
	}
	else {
		return false;
	}
}

//TALLIES UP THE NEIGHBORS FOR EACH CELL
bool tally(int row, int col, const vector <vector<char>>& grid) {
	/*
	A living cell with two or three neighboring living cells survives into the next generation.
	A living cell with fewer than two living neighbors dies of loneliness and a living cell with more than three living neighbors will die from overcrowding.
	Each empty/dead cell that has exactly three living neighbors--no more, no fewer-- comes to life in the next generation.
	*/
	bool state;
	if (grid[row][col] == '-') {
		state = deadStateTally(row, col, grid);
	}
	if (grid[row][col] == '*') {
		state = aliveStateTally(row, col, grid);
	}
	return state;
}

//CALCULATES OUT THE GENERATIONS BASED ON AN ORIGINAL GRID WHICH IS PASSED IN.
void calcRules(int generations, const vector <vector<char>>& origGrid) {
	vector <vector<char>> grid = origGrid;
	for (int i = 1; i < generations + 1; i++) {
		vector <vector<char>> newGen = grid;
		for (size_t row = 0; row < grid.size(); ++row) {
			for (size_t col = 0; col < grid[row].size(); ++col) {
				if (grid[row][col] != 'B') {
					bool state = tally(row, col, grid);
					if (state) newGen[row][col] = '*';
					else newGen[row][col] = '-';
				}
			}
		}
		cout << "Generation " << i << endl;
		printGrid(newGen);
		grid = newGen;
	}
}

//MAIN FUNCTION
int main() {
	//MAY TOUCH
	int generation = 2;

	//DON'T TOUCH
	string textfile = "Text.txt";
	vector <vector<char>> origGrid = initializingGrid(textfile);
	cout << "Original Grid" << endl;
	printGrid(origGrid);
	calcRules(generation, origGrid);
}