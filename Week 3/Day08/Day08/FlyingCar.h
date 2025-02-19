#pragma once
#include "Car.h"
class FlyingCar : public Car
{
public:

	//ctors
	//create a ctor that calls a base ctor
	FlyingCar(int year, std::string make, std::string model,
		int altitude, int maxAlt) :
		//call the base ctor
		Car(year, make, model),//a method call
		altitude_(altitude), 
		maxAlt_(maxAlt)
	{
	}
	//provide a new declaration for the override
	std::string vehicleInformation() override;

	//getters/setters
	int GetAltitude() const
	{
		return altitude_;
	}
	int MaxAltitude() const { return maxAlt_; }

	void SetAltitude(int newAltitude)
	{
		if (newAltitude >= 0 && newAltitude <= maxAlt_)
		{
			altitude_ = newAltitude;
		}
	}
	void MaxAltitude(int newMax)
	{
		if (newMax > 0 && newMax <= 6000)
		{
			maxAlt_ = newMax;
		}
	}
private:
	int altitude_, maxAlt_;

public:

};

