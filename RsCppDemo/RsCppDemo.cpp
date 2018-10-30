// RsCppDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>


template <class T>
struct container {
	template <class Iter> container(Iter, Iter);
	void insert(T arg);
	//...
};

template <class Iter>
container(Iter, Iter)
->container<typename std::iterator_traits<Iter>::value_type>;

void test(std::vector<int> v) {
	container c(v.begin(), v.end());

	c.insert();
}


template < typename T, typename ...Args >
constexpr T bitmask(Args... args) {
	return static_cast<T>(((1 << args) | ...));
}

constexpr auto mask = bitmask<uint8_t>(1, 4, 5);



int main()
{
    return 0;
}

