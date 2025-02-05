#pragma once
class Calculator
{
public:
	//the declaration of the sum method
	int minus(int number1, int number2);

	//a DECLARATION (how to communicate to the method)
	//return type Name(parameter list)
	//	parameters: require a type and a name
	int add(int num1, int num2);

	static double mult(double num, double factor);
};

