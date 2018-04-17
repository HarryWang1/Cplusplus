///*
//    testPrincess.cpp
//    Sec C
//    Cyclic Association
//*/
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//class FrogPrince;
//
//class Princess {
//    friend ostream& operator<<(ostream& os, const Princess& princess);
//public:
//    Princess(const string& name);
//    const string& getName() const;
//    void marries(FrogPrince& betrothed);
//private:
//    string name;
//    FrogPrince* spouse;
//};
//
//class FrogPrince {
//    friend ostream& operator<<(ostream& os, const FrogPrince& prince);
//public:
//    FrogPrince(const string& name);
//    const string& getName() const;
//    void setSpouse(Princess* pp);
//    //void setSpouse(Princess& pp) { spouse = &pp; }
//private:
//    string name;
//    Princess* spouse;
//};
//
//int main() {
//    Princess snowy("Snow White");
//    cout << snowy << endl;
//    FrogPrince froggy("Froggy");
//    cout << froggy << endl;
//    snowy.marries(froggy);
//    cout << snowy << endl;
//}
//
//
//// Princess code implementation
//const string& Princess::getName() const { return name; }
//
//Princess::Princess(const string& name) : name(name), spouse(nullptr) {}
//
//void Princess::marries(FrogPrince& betrothed) {
//    spouse = &betrothed;
//    //betrothed.spouse = this;
//    betrothed.setSpouse(this);
//}
//
//ostream& operator<<(ostream& os, const Princess& princess) { 
//    os << "Princess: " << princess.name;
//    if (princess.spouse != nullptr) {
//        os << ", spouse: " << princess.spouse->getName();
//    }
//    return os;
//}
//
//// FrogPrince code implementation
//FrogPrince::FrogPrince(const string& name) : name(name), spouse(nullptr) {}
//
//const string& FrogPrince::getName() const { return name; }
//
//void FrogPrince::setSpouse(Princess* pp) { spouse = pp; }
//
//ostream& operator<<(ostream& os, const FrogPrince& prince) { 
//    os << "FrogPrince: " << prince.name;
//    return os;
//}
