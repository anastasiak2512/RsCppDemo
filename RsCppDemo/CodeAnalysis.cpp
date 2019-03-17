// ReSharper C++ has its own code analyzer.
// It provides a bunch of C++ specific checks and catches a lot of typical faults.  

#include "stdafx.h"
#include <string>

// Quick-fix to generate a missing default case in a switch statement
inline const char* assess_operating_system(int windowsVersion) {
	switch (windowsVersion) {
	case 10:
		return "Excellent!";
	case 8:
		return "Meh but works";
	case 7:
		return "Try again!";
	}

	return nullptr;
}

// Change return type of the function
const char* change_return_type()
{
	std::string wrong_type( "asdf", 4);
	return wrong_type;
};

// Make data member mutable
void make_member_mutable()
{
	const struct
	{
		int n1;
		int n2;
	}

	const_struct = { 0, 0 };

	const_struct.n1 = 2;
	const_struct.n2 = 4;
}

// Usage of deprecated symbols
class __declspec(deprecated) deprecated_class
{
public:
	__declspec(deprecated)
		static int deprecated_function()
	{
		return 42;
	}
};

static void globalFunction()
{
	auto p = deprecated_class::deprecated_function();
}

// Usage of deleted functions
struct type_with_deleted_func
{
	type_with_deleted_func(int) = delete;
};

void foo(type_with_deleted_func t) {}

void bar()
{
	foo(1);
}

// May be const/static
class my_class
{
public:
	int get_meaning_of_life(int factor)
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
	int my_ch = (int)(ch);
	int my_d = (int)(d);
	int my_lng = (int)(lng);
}

// Expression result unused inspection with a quick-fix.
// Not all control paths return a value.
int expression_result_unused(int x)
{
	if (x == 1)
		return 1;
	else if (x == 2)
		return 2; // Expression result unused / quick-fix to return unused expression
	else if (x == 3)
		return 3;
}

// Using result of an assignement as a condition
void eqCheck(int& a, int& b) {
	if (a = b) {
		//...
	}
}

// Overload resolution errors
template<typename T, typename T::inner_type * = nullptr>
void foo(T) {}

struct X
{
	using inner_type = void;
};

struct Y {};

void test_inner(X x, Y y)
{
	foo(x);
	foo(y);
}

template<typename T, typename = decltype(T().method())>
void bar(T);

struct XM
{
	void method() {};
};

struct YM {};

void test_method(XM x, YM y)
{
	bar(x);
	bar(y);
}

struct A {};
template<class T,
	typename = std::enable_if_t<std::is_integral<T>::value>>
	void do_stuff() {}

void test_cond()
{
	do_stuff<A>();
}

struct P
{
	P() = delete;
};

void test_pair()
{
	std::pair<int, P>();
}

