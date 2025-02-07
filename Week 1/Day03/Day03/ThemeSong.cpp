#include "ThemeSong.h"
#include <iostream>

void ThemeSong::batTheme(int numberOfNas)
{
	for (int i = 0; i < numberOfNas; i++)
	{
		std::cout << "na ";
	}
	std::cout << "Batman!!\n";
}