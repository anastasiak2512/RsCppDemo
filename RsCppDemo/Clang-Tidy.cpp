#include "stdafx.h"
#include <functional>
#include <vector>
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
	class My_Class {
	public:
		My_Class(int x) :x(x) {

		}
		My_Class* operator&() {
			return this;
		}
	private:
		int x;
	};
}

