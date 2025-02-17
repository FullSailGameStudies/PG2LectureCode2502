#include "Spaceship.h"
#include "../../../Shared/Console/Console.h"

//the ctor definition should initialize all the fields
Spaceship::Spaceship()
{
	//initialize the fields
	x_ = Console::GetWindowWidth() / 2;
	y_ = Console::GetWindowHeight() / 2;
	speed_ = 0;
	rotation_ = 0;
}

//initialize using the member initialization list
Spaceship::Spaceship(int x, int y, int speed, int rotation) :
	//the member initialization list
	x_(x),
	y_(y),
	speed_(speed),
	rotation_(rotation)
{
	//speed = speed_;//backwards!!
}

void Spaceship::Shoot()
{
	//pewpew
}
