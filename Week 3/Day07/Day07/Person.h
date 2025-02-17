#pragma once
#include <string>
class Person
{
public:
	Person(int age, const std::string& name);
	void ItsMyBirthday();

	int Age() const { return age_; }
	void Age(int age)
	{
		if (age >= 0 && age <= 120)
			age_ = age;
	}
	const std::string& Name() const { return name_; }
	void Name(std::string name)
	{
		if (!name.empty() && name.size() < 64)
		{
			name_ = name;
		}
	}

private:
	int age_;
	std::string name_;
};

