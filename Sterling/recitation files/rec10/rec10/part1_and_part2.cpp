#include <iostream>
#include <vector>
using namespace std;

/*
Instrument
*/
class Instrument {
public:
	Instrument(){}

	virtual void  makeSound() const = 0;
	virtual void play() const  = 0;
private:

};
void Instrument::makeSound() const {
	cout << "To make a sound...";
}

/*
Brass
*/
class Brass : public Instrument {
public:
	Brass(unsigned size) : mouthpiece(size){}
	void makeSound() const override {
		Instrument::makeSound();
		cout << "blow on a mouthpiece of size " << mouthpiece << endl;
	}

	void play() const = 0;
private:
	unsigned mouthpiece;
};

class Trombone : public Brass {
public:
	Trombone(unsigned size) : Brass(size) {}
	void makeSound()  const override {
		Brass::makeSound();
	}

	void play() const override {
		cout << "Blat" << endl;
	}
private:
};

class Trumpet: public Brass {
public:
	Trumpet(unsigned size) : Brass(size) {}
	void makeSound()  const override {
		Brass::makeSound();
	}

	void play() const override {
		cout << "Toot" << endl;
	}
private:
};

/*
String 
*/
class String : public Instrument {
public:
	String(unsigned aPitch) : pitch(aPitch){}
	void makeSound()  const override {
		Instrument::makeSound();
		cout << "bow a string with a pitch " << pitch << endl;
	}

	void play() const = 0;
private:
	unsigned pitch;
};

class Violin : public String {
public:
	Violin(unsigned aPitch): String(aPitch){
	}
	void makeSound()  const override {
		String::makeSound();
	}
	void play() const override {
		cout << "Screech" << endl;
	}
private:
	unsigned pitch;
};

class Cello : public String {
public:
	Cello(unsigned aPitch) : String(aPitch) {
	}
	void makeSound()  const override {
		String::makeSound();
	}

	void play() const override {
		cout << "Squawk" << endl;
	}
private:
	unsigned pitch;
};

/*
Percussion
*/
class Percussion : public Instrument {
public:
	Percussion() {}
	void makeSound()  const override {
		Instrument::makeSound();
		cout << "hit me! " << endl;
	}
	void play() const = 0;
private:
};

class Drum : public Percussion {
public:
	void makeSound() const override {
		Percussion::makeSound();
	}

	void play() const override {
		cout << "Boom" << endl;
	}
private:
};

class Cymbal : public Percussion {
public:
	void makeSound()  const override {
		Percussion::makeSound();
	}

	void play() const override {
		cout << "Crash" << endl;
	}
private:
};

class Musician {
public:
    Musician() : instr(nullptr) {}

    void acceptInstr(Instrument* instPtr) { instr = instPtr; }

    Instrument* giveBackInstr() {
        Instrument* result(instr); 
        instr = nullptr;
        return result;
    }

    void testplay() const {
        if (instr) instr->makeSound(); 
        else cerr << "have no instr\n";
    }

	void play() const {
		if (instr) instr->play();
		else cerr << "Orchestra hasn't given me an instrument\n";
	}

private:
    Instrument* instr;
};

class Mill {
public:
	Mill() {}

	void receiveInstr(Instrument& instrument) {
		if (!storage.empty()) {
			for (size_t i = 0; i < storage.size(); ++i) {
				if (storage[i] == nullptr) {
					storage[i] = &instrument; 
				}
			}
			storage.push_back(&instrument);
		}
		else {
			storage.push_back(&instrument);
		}
	}

	Instrument* loanOut() {
		if (storage.empty()) {
			return nullptr;
		}
		else {
			for (size_t i = 0; i < storage.size(); ++i) {
				if (storage[i] != nullptr) {
					Instrument* temptr = storage[i];
					storage[i] = nullptr;
					return temptr;
				}
			}
			return nullptr;
		}
	}

	void dailytestplay() const {
		for (size_t i = 0; i < storage.size(); ++i) {
			if (storage[i] != nullptr) {
				storage[i]->makeSound();
			}
		}
	}

private:
	vector <Instrument*> storage;
};

class Orch {
public:
	Orch(){}

	void addPlayer(Musician& musician) {
		if (orchestra.size() == 25) {
			cout << "Cannot add more musicians" << endl;
		}
		orchestra.push_back(&musician);
	}

	void play() const{
		for (size_t i = 0; i < orchestra.size(); ++i) {
			orchestra[i]->play();
		}
	}

private:
	vector<Musician*> orchestra;
};

//// PART ONE
//int main() {
//     cout << "define some instruments ----------------------------------------\n";
//     drum drum;
//     cello cello(673);
//     cymbal cymbal;
//     trombone tbone(4);
//     trumpet trpt(12) ;
//     violin violin(567) ;
//  
//     // use the debugger to look at the mill
//     cout << "define the mill ------------------------------------------------\n";
//     mill mill;
//  
//     cout << "put the instruments into the mill ------------------------------\n";
//     mill.receiveinstr(trpt);
//     mill.receiveinstr(violin);
//     mill.receiveinstr(tbone);
//     mill.receiveinstr(drum);
//     mill.receiveinstr(cello);
//     mill.receiveinstr(cymbal);
//  
//     cout << "daily test -----------------------------------------------------\n";
//     cout << endl;
//     cout << "dailytestplay() const override" << endl;
//     mill.dailytestplay() const override;
//     cout << endl;
//  
//     cout << "define some musicians-------------------------------------------\n";
//     musician harpo;
//     musician groucho;
//  	
//     cout << "testing: groucho.acceptinstr(mill.loanout());-----------------------\n";
//     groucho.testplay() const override;	
//     cout << endl;
//     groucho.acceptinstr(mill.loanout());
//     cout << endl;
//     groucho.testplay() const override;
//     cout << endl;
//     cout << "dailytestplay() const override" << endl;
//     mill.dailytestplay() const override;
//  
//     cout << endl << endl;
//  
//     groucho.testplay() const override;	
//     cout << endl;
//     mill.receiveinstr(*groucho.givebackinstr());
//     harpo.acceptinstr(mill.loanout());
//     groucho.acceptinstr(mill.loanout());
//     cout << endl;
//     groucho.testplay() const override;
//     cout << endl;
//     harpo.testplay() const override;
//     cout << endl;
//     cout << "dailytestplay() const override" << endl;
//     mill.dailytestplay() const override;
//  
//     cout << "testing: mill.receiveinstr(*groucho.givebackinstr()); ----------\n";
//  
//     // fifth
//     mill.receiveinstr(*groucho.givebackinstr());
//     cout << "testing: mill.receiveinstr(*harpo.givebackinstr()); ------\n";
//     mill.receiveinstr(*harpo.givebackinstr());
//
//  
//     cout << endl;
//     cout << "dailytestplay() const override" << endl;
//     mill.dailytestplay() const override;
//     cout << endl;
//  
//     cout << endl;
//
//}


// PART TWO
int main() {
	// The initialization phase

	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12);
	Violin violin(567);

	Mill mill;
	mill.receiveInstr(trpt);
	mill.receiveInstr(violin);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;

	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr(mill.loanOut());
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr(mill.loanOut());

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr(mill.loanOut());
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr(*ralph.giveBackInstr());

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr(mill.loanOut());
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr(mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	// bob gets an instrument from the MIL2
	bob.acceptInstr(mill.loanOut());

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr(mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

} // main


