#include "stdafx.h"
#include <vector>
#include <memory>

//Navigate to type of symbol (ctrl+shift+t) shows all the options used
void test() {
	auto p = std::make_unique<std::vector<int>>();
	auto q = std::make_unique<std::string>();
	auto w = &p;
}