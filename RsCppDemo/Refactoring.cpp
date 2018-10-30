#include "stdafx.h"
#include <exception>
#include <iostream>

// Change Signature for callPerson(), use Ctrl + F6
typedef struct PersonData {
	int age;
	int id;
	const char *name;
} PersonData;

void callPerson(PersonData* p1, PersonData *p) {
	//TODO:
}

void usage() {
	PersonData p = { 64, 0, "Bjarne Stroustrup" };
	callPerson(nullptr, &p);
}

// Introduce field for error message text, use Ctrl + Alt + D
class ErrorHandler
{
	ErrorHandler()
	{
	}

public:
	void logError(std::exception& e)
	{
		auto errorLogFIle = fopen("log.txt", "w");
		fprintf(errorLogFIle, "Something has failed: %s", e.what());
		fclose(errorLogFIle);
	}

	void printError(std::exception& e)
	{
		printf("Something has failed: %s", e.what());
	}
};

// Introduce namespace alias for One::Two, use Ctrl + Shift + R
namespace One
{
	namespace Two
	{
		int ten = 10;
		inline void foo()
		{
			// do something
		}
	}
}

inline int test()
{
	One::Two::foo();
	return One::Two::ten;
}

// Inline Variable for result, use Ctrl + Alt + N
class InlineVariable
{
	static int getValue(int input1, int input2)
	{
		return input1 + input2;
	}

	static int getValueSquared(int input1, int input2)
	{
		auto result = input1 + input2;
		return result * result;
	}
};

// Convert if to ternary operator and back, use Alt + Enter on if
int convertIfTernary(bool cond)
{
	return cond ? 100 : -100;
}


// Substitute macro call
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

