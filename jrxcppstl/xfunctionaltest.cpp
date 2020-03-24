#include <iostream>
#include "xfunctional.h"

using namespace std;

class compare : public binary_function<int, int, bool>
{
	bool operator() (int  a, int b) const
	{
		return a > b;
	}
};

class compareronum : public unary_function<int, bool>
{
	bool operator() (int num) const
	{
		return num > 5;
	}
};