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

class Distance {
private:
	int feet = 0;
	int inches = 0;
public:

	Distance(const int feet, const int inches)
		: feet(feet),
		  inches(inches)
	{
	}

	Distance(const Distance& other)
		: feet{other.feet},
		  inches{other.inches}
	{
	}

	Distance(Distance&& other) noexcept
		: feet{other.feet},
		  inches{other.inches}
	{
	}


};
