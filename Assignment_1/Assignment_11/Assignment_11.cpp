// Assignment_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Dict.h"

using namespace std;

bool testDictSet();
bool testDictHas();
bool testDictGet();
bool testDictDel();
size_t one = 1;

bool testDictSet()
{
	Dict<int, string> map = Dict<int, string>();

	map.set(1, "a");
	map.set(1, "b");
	
	return map.domain().front() == 1 && map.range().front() == "a" && map.domain().size() == one && map.range().size() == one;
}

bool testDictHas()
{
	Dict<int, string> map = Dict<int, string>();

	map.set(1, "a");

	return map.has(1) && map.domain().size() == one && map.range().size() == one;
}

bool testDictGet()
{
	Dict<int, string> map = Dict<int, string>();

	map.set(1, "a");

	return map.get(1) == "a" && map.domain().size() == one && map.range().size() == one;
}

bool testDictDel()
{
	Dict<int, string> map = Dict<int, string>();

	map.set(1, "a");
	map.del(1);
	map.del(1);
	return !map.has(1) && map.domain().empty() && map.range().empty();
}

int main()
{
	cout << std::boolalpha;
	cout << "Test 1: " << testDictSet() << endl;
	cout << "Test 2: " << testDictHas() << endl;
	cout << "Test 3: " << testDictGet() << endl;
	cout << "Test 4: " << testDictDel() << endl;
}
