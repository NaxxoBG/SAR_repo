// Assignment_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Array_int_queue.h"
#include "List_int_queue.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

	Array_int_queue aq = Array_int_queue(4);
	List_int_queue lq = List_int_queue(4);

	cout << "Is the queue empty? " << aq.empty();

	aq.enqueue(1);

	cout << "\nIs the queue empty? " << aq.empty();

	cout << "\nIs the queue empty? " << lq.empty();

	lq.enqueue(1);

	cout << "\nIs the queue empty? " << lq.empty();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
