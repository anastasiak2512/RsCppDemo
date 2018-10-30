// ReSharper C++ has its own code analyzer.
// It provides a bunch of C++ specific checks and catches a lot of typical faults.  

#include "stdafx.h"

// Quick-fix to generate a missing default case in a switch statement
inline const char* assessOperatingSystem(int windowsVersion) {
	switch (windowsVersion) {
	case 10:
		return "Excellent!";
	case 8:
		return "Meh but works";
	case 7:
		return "Try again!";
	default: ;
	}

	return nullptr;
}

// Change return type of the function
const char* changeReturnType()
{
	const char* wrongType = "asdf";
	return wrongType;
};

// Make data member mutable
void makeMemberMutable()
{
	const struct
	{
		mutable int n1;
		mutable int n2;
	}

	constStruct = { 0, 0 };

	constStruct.n1 = 2;
	constStruct.n2 = 4;
}

// Usage of deprecated symbols
class __declspec(deprecated) DeprecatedClass
{
public:
	__declspec(deprecated)
		static int deprecatedFunction()
	{
		return 42;
	}
};

static void globalFunction()
{
	auto p = DeprecatedClass::deprecatedFunction();
}

// Usage of deleted functions
struct typeWithDeletedFunc
{
	typeWithDeletedFunc(int) = delete;
};

void foo(typeWithDeletedFunc t) {}

void bar()
{
	foo(1);
}

// May be const: local var, parameter, member function
class myClass
{
private:
	int x = 0;
	int y = 0;
public:
	int getMeaningofLife(int factor)
	{
		return 42 * factor;
	}
};

// Override function redefines a default parameter argument
class Base
{
public:
	virtual int someMethod(const int x, const int factor = 1) const
	{
		return 42 * x * x * factor;
	}
};
class Derived : public Base
{
public:
	int someMethod(const int x, const int factor = 0) const override
	{
		return x * x * factor;
	}
};

// Prefer C++ cast to C style cast
void avoid_c_style_cast(char ch, double d, long long lng)
{
	int my_ch = static_cast<int>(ch);
	int my_d = static_cast<int>(d);
	int my_lng = static_cast<int>(lng);
}

// Invalid format specifiers, check the quick-fix
void invalidFormatSpecifier(int num, char * str) {
	printf("Input param: %d, %s", num, str);
}

// Expression result unused inspection with a quick-fix.
// Not all control paths return a value.
int ExpressionResultUnused(int x)
{
	if (x == 1)
		return 1;
	else if (x == 2)
		2; // Expression result unused / quick-fix to return unused expression
	else
		return 3;
}

// Using result of an assignement as a condition
void eqCheck(int& a, int& b) {
	if (a = b) {
		//...
	}
}

