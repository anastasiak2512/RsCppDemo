#include "stdafx.h"
#include <functional>
#include <iostream>

// Modernize: lambda instead of bind
int add(int x, int y) { return x + y; }

void bind_to_lambda(int num) {
	int x = 2;
	auto clj = std::bind(add, x, num);
}

//Modernize: use std::move
class MyClass {
public:
	MyClass(const std::string &Copied,
		const std::string &ReadOnly)
		: Copied(Copied), ReadOnly(ReadOnly) {}

private:
	std::string Copied;
	const std::string &ReadOnly;
};

// Google checks: explicit constructor
namespace my_namespace {
	class my_class {
	public:
		my_class(const int x) :x_(x) {

		}
		my_class* operator&() {
			return this;
		}
	private:
		int x_;
	};
}

// ReSharper disable once CppInconsistentNaming
struct S {
	int x;
	operator bool() const { return true; }
};

bool f() {
	const S a{ 1 };
	const S b{ 2 };
	return a == b;
}

