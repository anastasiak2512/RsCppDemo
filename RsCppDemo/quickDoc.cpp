// Quick Documentation (Ctrl + Q) provides you with tons of useful information about the code:
// - documentation, comments (on hover)
// - derived types info
// - macro substitution

#include "stdafx.h"
#include <string>

/// Code comments
class doc_class
{
	//..
};

// Documentation for templates
template<class...> struct Tuple { };
///First overload
template<class... Types>
void handle(Tuple<Types ...>) { std::cout << "1\n"; }
///Second overload
template<class T1, class... Types>
void handle(Tuple<T1, Types ...>) { std::cout << "2\n"; }
///Third overload
template<class T1, class... Types>
void handle(Tuple<T1, Types& ...>) { std::cout << "3\n"; }

void check() {
	handle(Tuple<>()); 
	handle(Tuple<int, float>());
	handle(Tuple<int, float&>());
	handle(Tuple<int>());
}

// Multi-line documentation 
/// @brief The date of nth x-day in month.
/// @return The date.
int checkNday(int n, ///< [in] The number of the x-day.
	int x, ///< [in] x = 0 means Sunday, x = 1 means Monday, and so on.
	int month, ///< [in] Month given.
	int year, ///< [in] Year given.
	int day = 0 ///< [in] Day given. If day is omitted or 0, it defaults
				///       to 1 if n>0, and month's last day otherwise.
) {
	//TODO:
	return 1;
}

// Documentation generation: document undocumentedFunc() via Alt+Enter
// Template can be configured in Tools | Templates Explorer | Live Templates | C/C++

float undocumentedFunc(int idx, float coeff, std::string name)
{
	// doSmth();
	return 0.0;
}

// Check the type of x, y, z; convert auto to the deduced type.
template<class T, class U>
auto add(T t, U u) { return t + u;  }

void inferType()
{
	auto x = add(1, 2);
	auto y = add(1, 2L);
	auto z = add(1, 2.0);
}

// Check the type of a, b; convert auto to the explicit type.
struct Val
{
	long a;
	short b;
};

template<int Idx>
auto & get(Val& v)
{
	if constexpr (Idx == 0)
		return v.a;
	else
		return v.b;
}

void inferTypeConstexpr()
{
	Val v{1000, 1};
	auto a = get<0>(v);
	auto b = get<1>(v);
}

// Check the macro substitution;
// Substitute one call or all
#define MAGIC 100
#define CALL_DEF(val, class_name) int call_##class_name() { return val; }

#define CLASS_DEF(class_name) class class_##class_name { \
                              public: \
                                  int count_##class_name; \
                                  CALL_DEF(MAGIC, class_name) \
                              };

CLASS_DEF(A)
CLASS_DEF(B)
CLASS_DEF(C)

// Understanding of the fold expressions and ability to calculate it.
template < typename T, typename ...Args >
constexpr T bitmask(Args... args) {
	return static_cast<T>(((1 << args) | ...));
}

constexpr auto mask = bitmask<uint8_t>(1, 4, 5);
