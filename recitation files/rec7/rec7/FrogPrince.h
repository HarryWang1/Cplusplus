#ifndef FROGPRINCE_H
#define FROGPRINCE_H

#include <iostream>
#include <string>

namespace Fantasy {

    class Princess;

    class FrogPrince {
        friend std::ostream& operator<<(std::ostream& os, 
                                        const FrogPrince& prince);
    public:
        FrogPrince(const std::string& name);
        const std::string& getName() const;
        void setSpouse(Princess* pp);
        //void setSpouse(Princess& pp) { spouse = &pp; }
    private:
        std::string name;
        Princess* spouse;
    };

}

#endif
