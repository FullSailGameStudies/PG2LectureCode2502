#pragma once

struct Color
{
	//default access is public
	int red, green, blue, alpha;
	Color() : red(0), green(0), blue(0), alpha(255)
	{	}
	Color(int r,int g, int b, int a) :
		red(r), green(g), blue(b), alpha(a) { }
};