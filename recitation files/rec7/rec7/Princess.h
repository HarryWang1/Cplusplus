#ifndef PRINCESS_H
#define PRINCESS_H

#include <iostream>
#include <string>

namespace Fantasy {

    class FrogPrince;

    class Princess {
        friend std::ostream& operator<<(std::ostream& os, 
                                        const Princess& princess);
    public:
        Princess(const std::string& name);
        const std::string& getName() const;
        void marries(FrogPrince& betrothed);
    private:
        std::string name;
        FrogPrince* spouse;
    };

}

#endif
