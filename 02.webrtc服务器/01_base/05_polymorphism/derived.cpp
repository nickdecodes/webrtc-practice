#include <iostream>

#include "AirPlane.h"
#include "FighterPlane.h"
#include "NonePlane.h"

int main(int argc, char* argv[]) {
    avdance::AirPlane* ap = new avdance::FighterPlane();
    if (ap) {
        ap->fly();
    }

    ap = new avdance::NonePlane();
    if (ap) {
        ap->fly();
    }

    ap = new avdance::AirPlane();
    if (ap) {
        ap->fly();
    }
}
