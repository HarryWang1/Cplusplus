/*
    testPrincess.cpp
    Sec C
    Separate Compilation
*/

#include <iostream>
#include <string>
#include <string>
#include "Princess.h"
#include "Princess.h"
#include "FrogPrince.h"
using namespace std;
//using namespace Fantasy;

int main2() {
    //Princess snowy("Snow White");
    Fantasy::Princess snowy("Snow White");
    cout << snowy << endl;
    //FrogPrince froggy("Froggy");
    Fantasy::FrogPrince froggy("Froggy");
    cout << froggy << endl;
    snowy.marries(froggy);
    cout << snowy << endl;
	return 1;
}
