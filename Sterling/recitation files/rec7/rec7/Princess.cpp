#include "Princess.h"
#include "FrogPrince.h"
#include <string>
using namespace std;

namespace Fantasy {

    // Princess code implementation
    const string& Princess::getName() const { return name; }

    Princess::Princess(const string& name) : name(name), spouse(nullptr) {}

    void Princess::marries(FrogPrince& betrothed) {
        spouse = &betrothed;
        //betrothed.spouse = this;
        betrothed.setSpouse(this);
    }

    ostream& operator<<(ostream& os, const Princess& princess) { 
        os << "Princess: " << princess.name;
        if (princess.spouse != nullptr) {
            os << ", spouse: " << princess.spouse->getName();
        }
        return os;
    }

}
