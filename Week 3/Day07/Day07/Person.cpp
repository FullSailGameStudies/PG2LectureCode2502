#include "Person.h"
#include <iostream>

void Person::ItsMyBirthday()
{
	age_++;
	std::cout << "It's my birthday! I am " << age_ << " years old!\n";
	std::cout << "Let's have some cake!!\n";
}

Person::Person(int age, const std::string& name)
	: age_(age), name_(name)
{
}
