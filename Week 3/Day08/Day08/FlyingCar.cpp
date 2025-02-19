#include "FlyingCar.h"

std::string FlyingCar::vehicleInformation()
{
    //do I want to EXTEND the base version or COMPLETELY OVERRIDE the base?
    //EXTENDING the base means CALLING the base version
    std::string baseInfo = Car::vehicleInformation();
    std::string derivedInfo = "\n\tMax Altitude: " + std::to_string(maxAlt_);
    return baseInfo + derivedInfo;
}
