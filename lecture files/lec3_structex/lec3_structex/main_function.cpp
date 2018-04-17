/*
lec03
Justin Lin

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Word {
	string token;
	vector <int> positions;
};

size_t findWord(const string& token, const vector<Word>& words);

int main() {
	vector <Word> words;
	ifstream ifs("jabberwocky.txt");
	if (!ifs) {
		cerr << "Unable to open file";
		exit(1);   // call system to stop
	}

	string token;
	int pos = 0;

	while (ifs >> token) {
		size_t index = findWord(token, words);
		if (index == words.size()) {
			Word aWord;
			aWord.token = token;
			aWord.positions.push_back(pos);
		}
		else {
			words[index].positions.push_back(pos);
		}
		++pos;
	}

	//Print out
	/*
	Don't do const int& var, b/c it copies the address of the int, which is just as big as the int. 
	*/
	for (const Word& word : words) {
		cout << word.token << ": ";
		for (int pos : word.positions) {
			cout << pos << ", ";
		}
		//cout << endl;
		cout << ".\n";
	}

	for (size_t i = 0; i < words.size(); ++i) {
		cout << words[i].token << ':';
		for (size_t j = 0; j < words[i].positions.size(); ++j) {
			cout << ' ' << words[i].positions[j];
		}
		cout << ".\n";
	}

	ifs.close();
}

/*
Note: Problem here is that you have an size_t to keep track of the index, but the function is returning int. 
size_t is an unsigned int, so if you have something exceeding 2B, then you could have it cut off due to the return
type of the function. 

So what you should do, is make the function size_t, and return the words.size() if it is too big, b/c i can never
reach the size of the vector b/c it starts position 0. 
*/

size_t findWord(const string& token, const vector<Word>& words) {
	for (size_t i = 0; i < words.size() - 1; i++) {
		if (token == words[i].token) {
			return int(i);
		}
	}
	return words.size();
}