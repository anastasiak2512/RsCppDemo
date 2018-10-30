// ReSharper C++ has its own code analyzer.
// It provides quick-fixes to make the code cleaner, with wider usage of modern C++.
// Check the inspection settings for C++, group Common Practices and Code Improvements

#include "stdafx.h"
#include <string>

// Replace with constexpr when the condition is a compile-time constant expression (C++17)
void constexpr_case()
{
	if (sizeof(long) == 4)
	{
		//...
	}
}

// Convert to nested namespace definition (C++17)
namespace one
{
	namespace two
	{
		namespace Three {
			int GetMeaningOfLife()
			{
				return 42;
			}
		}
	}
}

// Join declaration and assignment
void joinDeclAssign()
{
	std::string s;
	// ... no use of s here ...
	s = "what a waste";
}

// C-cast instead of C++ style cast: get all proper casts automatically
enum class Num { ONE = 1, TWO, THREE };

class Base {
public:
	virtual void test() {}
	virtual ~Base() {}
};

class Derived : public Base {
public:
	 void name() const {}
};

int answer() { return 42; }

void static_cast_sample() {
	Num n = Num::TWO;
	int one = (int)n;
}

void reinterpret_cast_sample() {
	void(*fun_pointer)() = (void(*)())answer;
}

void const_cast_sample() {
	const int j = 42;
	int* pj = (int *)&j;
}

// Replace expression with boolean
class ReplaceZeroWithBoolean
{
	static bool getFalseValue()
	{
		return 0;
	}

	static bool getTrueValue()
	{
		return 1000;
	}
};