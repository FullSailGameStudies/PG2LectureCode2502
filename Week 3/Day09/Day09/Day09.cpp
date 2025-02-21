// Day09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Pistol.h"
#include "Knife.h"
#include <vector>


class base
{
private:
	int mNum;
public:
	base(int num) : mNum(num)
	{

	}
	void print()
	{
		std::cout << "Hello base " << mNum << "\n";
	}
};

class derived : public base
{
private:
	std::string mStr;
public:
	derived(std::string str, int num) : base(num), mStr(str)
	{ }
};


class Car
{
public:
	Car(int year)
	{
		mModelYear = year;
		mNumberOfCarsMade++;
	}

	int mModelYear; //each car has its own model year variable
	static int mNumberOfCarsMade; //shared by ALL cars. There is ONLY ONE mNumberOfCarsMade

	//static methods do NOT have a 'this' parameter
	//static methods can ONLY access static members (fields and methods)
	static void reporting()
	{
		//std::cout << "Model year: " << this->mModelYear << "\n"; //ERROR! cannot access non-static members
		std::cout << "Number of cars made: " << mNumberOfCarsMade << "\n";
	}

	//non-static methods have
	//a hidden parameter called 'this'
	//non-static methods can access non-static AND static members
	void vehicleInfo() 
	{
		std::cout << "Model Year: " << this->mModelYear << "\n";
	}
};
//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0;



int main()
{
	Car myRide(2009);
	myRide.vehicleInfo();
	Car yourRide(2020);
	yourRide.vehicleInfo();
	Car::reporting();
	Pistol banger(50, 100, 10, 2);
	//only going to copy the weapon parts of banger
	Weapon currentWeapon = banger;

	std::vector<Weapon*> wicksBackpack;
	wicksBackpack.push_back(&banger);

	//pCurrent
	Weapon* pCurrent = &banger;//ALWAYS safe. upcasting
	//Pistol* ptrPistol = pCurrent;//NOT SAFE! downcasting is not safe.
	pCurrent = new Knife(3, 5, 2);
	wicksBackpack.push_back(pCurrent);
	wicksBackpack.push_back(new Knife(5, 20, 3));

	for (auto& wpnPtr : wicksBackpack)
	{
		wpnPtr->showMe();//runtime polymorphism!!
	}
	
	int* pNum = new int(5);
	//pNum = &banger;

	//type* creates a pointer variable to the object of that type
	//the pointer variable ONLY stores the memory location of 
	//the object it points to.
	//on the right-hand side, & means address-of
	Pistol* pPistol = &banger;
	//64-bit apps, pointers are 8-byte integers
	std::cout << pPistol << "\n";

	// = new means Heap memory is being used
	// for every `= new` you NEED a corresponding `delete`
	pPistol = new Pistol(100, 50, 15, 1);
	Pistol* pPistol2 = pPistol;
	delete pPistol;//clean up the memory
	pPistol = nullptr;

	if(pPistol2 != nullptr)
		pPistol2->calcDamage();

	std::vector<std::unique_ptr<Weapon>> dorasBackpack;
	std::unique_ptr<Pistol> uPtr = 
		std::make_unique<Pistol>(100, 50, 15, 1);
	uPtr->Rounds(10);
	dorasBackpack.push_back(std::move(uPtr));
	//std::unique_ptr<Pistol> uPtr2 = std::move(uPtr);
	//uPtr->Rounds(10);

	/*
		╔════════════╗
		║ Unique_ptr ║
		╚════════════╝

		Using unique pointers w/ overridden methods


		╔═══════════╗
		║ UPCASTING ║ - casting a derived type variable to a base type variable
		╚═══════════╝

		This is ALWAYS safe.


		To maintain the original object, we need a pointer though. If not, then we're just calling the copy constructor of the base class and lose all the info of the derived.

		Unique pointers owns and manages an object through a pointer.
		std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 5);


		You can upcast by using the base type in the unique_ptr.
		std::unique_ptr<base> pBase = std::make_unique<derived>("Gotham", 5);
		  OR
		std::unique_ptr<base> pBase = std::move(pDerived); https://learn.microsoft.com/en-us/cpp/standard-library/utility-functions?view=msvc-170&redirectedfrom=MSDN&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(std%253A%253Amove)%3Bk(move)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue#move



		Lecture Code:
			use make_unique and unique_ptr to create a derived instance
			use std::move to upcast it to a base
	*/
	derived der1("Gotham", 1);
	base base1 = der1; //calls the assignment operator of base therefore you lose all the derived parts. base1 is JUST a base object.
	der1.print();
	std::cout << "\n";
	base1.print();



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

		Create a vector that holds unique pointers of Weapon.
		Create instances of Weapon and Pistol using make_unique.
		Add them to the vector.

		Loop over the vector and call showMe on each weapon.

	*/




	/*
		╔══════════════════╗
		║  Static Members  ║
		╚══════════════════╝

		When calling a non-static method on a class, you must use a variable of that class.
		That's because the variable is passed in as the 'this' parameter.

		Static methods do not have a 'this' parameter therefore you call them on the
		class name itself.

		That's also why static methods cannot access non-static members.

	*/
	Car myRide(1988);
	Car::reporting();
	myRide.vehicleInfo();//calling non-static methods. myRide is passed in for 'this'

	/*

		CHALLENGE:
		Add a static method to the Car class that returns an instance of the Car class.

	*/
}