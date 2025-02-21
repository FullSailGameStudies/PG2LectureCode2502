#pragma once
#include "Weapon.h"

class Knife : public Weapon
{
public:
private:
	int length_;
public:

	Knife(int range, int damage, int length)
		: Weapon(range,damage), length_(length)
	{
	}
};