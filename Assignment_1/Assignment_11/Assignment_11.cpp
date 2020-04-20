// Assignment_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Dict.h"

using namespace std;

bool testDictSet();
bool testDictHas();
bool testDictGet();
bool testDictDel();

bool testDictSet()
{
	Dict<int, string> map = Dict<int, string>();

	map.set(1, "a");
	
	return map.domain().front() == 1 && map.range().front() == "a";
}

bool testDictHas()
{
	Dict<int, string> map = Dict<int, string>();

	map.set(1, "a");

	return map.has(1);
}

bool testDictGet()
{
	Dict<int, string> map = Dict<int, string>();

	map.set(1, "a");

	return map.get(1) == "a";
}

bool testDictDel()
{
	Dict<int, string> map = Dict<int, string>();

	map.set(1, "a");
	map.del(1);
	return !map.has(1);
}

int main()
{
	cout << std::boolalpha;
	cout << "Test 1: " << testDictSet() << endl;
	cout << "Test 2: " << testDictHas() << endl;
	cout << "Test 3: " << testDictGet() << endl;
	cout << "Test 4: " << testDictDel() << endl;
}
