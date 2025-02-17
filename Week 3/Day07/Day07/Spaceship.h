#pragma once
class Spaceship
{
	//describing the class
	// what the object can do? (behaviors, methods)
	// information about the object (fields, data)

	//position, rotation, speed, numberoflives
	//shoot, accelerate, hyperjump

public:
	//constructors (ctor):
	//  IF I do not write a ctor, the compiler will give me a default ctor
	//  a default ctor: no parameters
	//	IF I write a ctor, the compiler's version is not longer available
	// the ctors should provide a value for all the fields
	Spaceship(); //a default ctor
	Spaceship(int x, int y, int speed, int rotation);


	// methods
	//  PascalNamingConvention (C#, Java)
	//	_stricmp, rand  (oldschool, OG)
	//  push_back
	//declaration in the header, definition in the cpp for MOST methods

	void Shoot();

	//Spaceship()


	//getters (accessors)
	//  DO NOT change the fields
	//	return type matches the field type
	int GetRotation() const { return rotation_; }
	int Speed() const { return speed_; }

	//setters (mutators)
	//  can change the fields
	//  return type is most of the time void
	//	will need at least 1 parameter for setting the field
	void SetRotation(int rotation)
	{
		if (rotation >= 0)//gatekeeping
			rotation_ = rotation;
	}
	void Speed(int newSpeed)
	{
		if (newSpeed >= 0 && newSpeed <= 20)
		{
			speed_ = newSpeed;
		}
	}

private:
	//make fields private most of the time
	//fields are the data (class variables, data members)
	//naming convention for fields:
	//  camelCasingNamingConvention
	//	m_ or m or _
	//  m_x, mX, _x, x_, m_iX
	int x_, y_;//position
	int rotation_;
	int speed_;

	void info(int x, int y)
	{
		int rotation = rotation_;
	}

};

