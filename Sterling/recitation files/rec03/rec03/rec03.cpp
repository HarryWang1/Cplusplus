/*
rec03
Justin Lin
1.26.18

The Game of Life
/*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

//Minesweeper class to contain the game
class Minesweeper {

	//SubClass//
	//Tile class, tile per grid.
	class Tile {
	public:
		Tile(bool isBomb, int numBombs, bool isVisible, int cRow, int cCol) :
			bomb(isBomb), numberBombs(numBombs), visible(isVisible), coorRow(cRow), coorCol(cCol) {}
		//Variables
		bool bomb;
		bool visible;
		int numberBombs;
		int coorRow, coorCol;

	};

	//Class Defined Members
public:
	//Prototype:
	//Constructors
	//Initializes the minesweeper game
	Minesweeper(int numRow, int numCol) : row(numRow), col(numCol) {
		srand(time(NULL));
		for (int i = 0; i < row; ++i) {
			vector <Tile> tempVec;;
			for (int j = 0; j < col; ++j) {
				int random = rand() % 10;
				if (random < 2) {
					Tile tempTile(true, 0, false, i, j);
					tempVec.push_back(tempTile);
				}
				else {
					Tile tempTile(false, 0, false, i, j);
					tempVec.push_back(tempTile);
				}
			}
			grid.push_back(tempVec);
		}
		modifyBombNeighbor();
	}

	//Displays the board
	void display(bool reveal) const {
		cout << "Choose a number from: 0 to " << (col) << endl;
		if (reveal) {
			for (int selRow = 0; selRow < row; ++selRow) {
				for (int selCol = 0; selCol < col; ++selCol) {
					if (grid[selRow][selCol].bomb) {
						cout << "|" << "B";
					}
					else {
						cout << "|" << grid[selRow][selCol].numberBombs;
					}

				}
				cout << endl;
			}
		}
		else {
			for (int selRow = 0; selRow < row; ++selRow) {
				for (int selCol = 0; selCol < col; ++selCol) {
					if (!grid[selRow][selCol].visible) {
						cout << "|" << "?";
					}
					else if (grid[selRow][selCol].visible) {
						if (grid[selRow][selCol].numberBombs == 0) {
							cout << "|" << " ";
						}
						else {
							cout << "|" << grid[selRow][selCol].numberBombs;
						}

					}
					else {
						continue;
					}
				}
				cout << endl;
			}
		}
	}

	//Tells and returns if the game is done
	bool done() {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (grid[i][j].bomb == true && grid[i][j].visible) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}

	//Checks if the row is valid
	bool validRow(int selRow) const {
		if (selRow < 0 || selRow == row) {
			return false;
		}
		else {
			return true;
		}
	}

	//Checks valid col
	bool validCol(int selCol) const {
		if (selCol < 0 || selCol == row) {
			return false;
		}
		else {
			return true;
		}
	}

	//Checks if a tile is visible
	bool isVisible(int selRow, int selCol) {
		return grid[selRow][selCol].visible;
	}

	//Helps initializes the board, by giving the tiles the # of neighbors of bombs
	void modifyBombNeighbor() {
		for (int selRow = 0; selRow < row; ++selRow) {
			for (int selCol = 0; selCol < col; ++selCol) {
				if (grid[selRow][selCol].bomb) {
					for (int ctrlRow = -1; ctrlRow < 2; ++ctrlRow) {
						for (int ctrlCol = -1; ctrlCol < 2; ++ctrlCol) {
							if (validCol(selCol + ctrlCol) && validRow(selRow + ctrlRow)) {
								if (!grid[selRow + ctrlRow][selCol + ctrlCol].bomb) {
									grid[selRow + ctrlRow][selCol + ctrlCol].numberBombs += 1;
								}
							}
						}
					}
				}
			}
		}
	}

	//adds 8 surrounding tiles to the todo list if it is 0 neighbor
	void eightCall(vector <Tile>& todo, const Tile& current) const {
		for (int i = -1; i < 2; ++i) {
			for (int j = -1; j < 2; ++j) {
				if (validRow(current.coorRow + i) && validCol(current.coorCol + j)) {
					todo.push_back(grid[current.coorRow + i][current.coorCol + j]);
				}
			}
		}
	}

	//Plays the game
	bool play(int selRow, int selCol) {
		vector<Tile> todo;
		//If it is a bomb
		if (grid[selRow][selCol].bomb) {
			finished = true;
			return false;
		}
		//If it is not a bomb and the neighbors are greater than 0.
		else if (!grid[selRow][selCol].bomb && grid[selRow][selCol].numberBombs > 0) {
			grid[selRow][selCol].visible = true;
			if (!todo.empty()) {
				todo.pop_back();
			}
		}
		else {
			todo.push_back(grid[selRow][selCol]);
		}

		while (!todo.empty()) {
			Tile current = todo.back();
			todo.pop_back();
			if (current.bomb) { continue; }
			else if (grid[current.coorRow][current.coorCol].visible) { continue; }
			else if (!current.bomb && current.numberBombs == 0) {
				grid[current.coorRow][current.coorCol].visible = true;
				eightCall(todo, current);
			}
			else if (!current.bomb && current.numberBombs > 0) {
				grid[current.coorRow][current.coorCol].visible = true;
			}
			else {
				continue;
			}
		}
		return true;

	}

private:
	vector <vector<Tile>> grid;
	int row, col;
	bool finished;
};


int main() {
	Minesweeper sweeper(10, 10);
	// Continue until only invisible cells are bombs
	while (!sweeper.done()) {
		sweeper.display(false); // display board without bombs

		int row_sel = -1, col_sel = -1;
		while (row_sel == -1) {
			// Get a valid move
			int r, c;
			cout << "row? ";
			cin >> r;
			r = r - 1;
			if (!sweeper.validRow(r)) {
				cout << "Row out of bounds\n";
				continue;
			}
			cout << "col? ";
			cin >> c;
			c = c - 1;
			if (!sweeper.validRow(c)) {
				cout << "Column out of bounds\n";
				continue;
			}
			if (sweeper.isVisible(r, c)) {
				cout << "Square already visible\n";
				continue;
			}
			row_sel = r;
			col_sel = c;
		}
		// Set selected square to be visible. May effect other cells.
		if (!sweeper.play(row_sel, col_sel)) {
			cout << "Sorry, you died..\n";
			sweeper.display(true); // Final board with bombs shown
			exit(0);
		}
	}
	// Ah! All invisible cells are bombs, so you won!
	cout << "You won!!!!\n";
	sweeper.display(true); // Final board with bombs shown

}

