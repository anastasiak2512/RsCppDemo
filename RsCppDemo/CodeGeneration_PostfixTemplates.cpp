// Postfix templates / completion let you generate wrapping code in one click

#include "stdafx.h"
#include <vector>

class testClass
{
	
};

// Regular live templates: ns, main, enumclass, etc.

// Postfix live templates: casts, control flow, new, return, make_shared, make_unique
void postfixTemplates(int val)
{
	switch (val) {  }
	while (val) 

	std::vector<int> v{ 1, 0, 100, 1000 };
	//v.foreach

}

enum class Num { ONE = 1, TWO, THREE };
struct Base {
	virtual ~Base() {}
};
struct Derived : Base {
	virtual void name() {}
};

void static_cast_sample() {
	Num n = Num::TWO;
	int one = static_cast<int>(n);
}
