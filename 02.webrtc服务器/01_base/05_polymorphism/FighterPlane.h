#ifndef __FIGHTERPLANE_H__
#define __FIGHTERPLANE_H__

#include <iostream>
#include "AirPlane.h"

namespace avdance {

class FighterPlane: public AirPlane {

public:
    FighterPlane() {
        std::cout << "FighterPlane construct..." << std::endl;
        weapons = 1;
    }

    ~FighterPlane() {
        std::cout << "FighterPlane destruct ..." << std::endl;
    }

public:
    void setWeapons(int w);
    int getWeapons();

public:
    virtual void fly() {
        std::cout << "FighterPlane fly..." << std::endl;
    }


private:
    int weapons;

};

}//namespace

#endif //__FIGHTERPLANE_H__
