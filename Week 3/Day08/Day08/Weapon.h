#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);

	//pure virtual method which 
	//makes the class abstract
	//which means we cannot create a Weapon instance
	virtual void showMe() = 0;
	int calcDamage();

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

