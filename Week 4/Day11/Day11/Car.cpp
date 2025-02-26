#include "Car.h"

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

void Car::SerializeCSV(std::ofstream& outFile, char delimiter)
{
	outFile << mModelYear << delimiter << mMake << delimiter << mModel;
}
