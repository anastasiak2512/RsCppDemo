#include "stdafx.h"
#include <vector>
#include <memory>

//Navigate to type of symbol (ctrl+shift+t) shows all the options used
void test() {
	auto p = std::make_unique<std::vector<int>>();
	auto q = std::make_unique<std::string>();
	auto w = &p;
}

//Go to Text for going to any expression...
//Get all results by clicking a button
//space - search first, then search second, etc.
//Match by camel humps, prefix
//

//Filter usages: read, write, binding
//find usage : const ref and ref are in different groups (both reads, one of it is binding unconst)

//sqrt - include - several options, we have a list build for all standard functions

//Show template argument (deduction guides) explicitly

//Find Usages or any other view. Select functions - set breakpoints or tracepoints for all.

//Unit testing: from command line you can't jump to source, rerun one test (with breakpoint), grouping, rerun failed tests.

//Formatting: selection, get options for this selection, change only those applicable to this place

//Step filters, more powerful than Only my code

//Inline variables view. VS visualizers + some features, mark field as highlight for example.

//Navigate to breakpoint in entity, you can filter

void test2()
{
	
}
