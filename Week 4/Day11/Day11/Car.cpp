#include "Car.h"

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

void Car::SerializeCSV(std::ostream& outFile, char delimiter)
{
	outFile << mModelYear << delimiter << mMake << delimiter << mModel;
}

void Car::DeserializeCSV(const std::string& csvData, char delimiter)
{
	std::stringstream carStream(csvData);
	std::string yearString;
	std::getline(carStream, yearString, delimiter);
	mModelYear = std::stoi(yearString);
	std::getline(carStream, mMake, delimiter);
	std::getline(carStream, mModel);
}
