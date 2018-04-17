#include "FrogPrince.h"
#include "Princess.h"
using namespace std;

namespace Fantasy {

    // FrogPrince code implementation
    FrogPrince::FrogPrince(const string& name) : name(name), spouse(nullptr) {}

    const string& FrogPrince::getName() const { return name; }

    void FrogPrince::setSpouse(Princess* pp) { spouse = pp; }

    ostream& operator<<(ostream& os, const FrogPrince& prince) { 
        os << "FrogPrince: " << prince.name;
        return os;
    }

}
