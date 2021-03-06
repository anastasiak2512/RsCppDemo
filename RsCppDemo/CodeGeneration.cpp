// ReSharper C++ can generate:
// - constructors, copy, move
// - getters, setters
// - operators and hash/swap functions
// - live and postfix live templates
// - documentation

#include "stdafx.h"
#include <utility>
#include <tuple>
#include <ostream>

class MyDistance {
private:
	int feet = 0;
	int inches = 0;
public:


	MyDistance(int feet, int inches)
		: feet(feet),
		  inches(inches)
	{
	}

	friend std::ostream& operator<<(std::ostream& os, const MyDistance& obj)
	{
		return os
			<< "feet: " << obj.feet
			<< " inches: " << obj.inches;
	}
};
