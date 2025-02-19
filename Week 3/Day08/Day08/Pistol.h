#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:
	Pistol(int range, int damage, int rounds, int magCapacity) : 
		Weapon(range,damage),
		rounds_(rounds), 
		magCapacity_(magCapacity)
	{
	}

	int Rounds() const { return rounds_; }
	void Rounds(int rounds)
	{
		if (rounds >= 0 && rounds <= magCapacity_)
			rounds_ = rounds;
	}
	int MagCapacity() const { return magCapacity_;}
	void MagCapacity(int magCap)
	{
		if (magCap > 0 && magCap <= 15)
			magCapacity_ = magCap;
	}

private:
	int rounds_, magCapacity_;

};

