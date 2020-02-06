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

	/*cout << "Is the queue empty? " << aq.empty();

	aq.enqueue(1);

	cout << "\nIs the queue empty? " << aq.empty();*/

	cout << "\nIs the queue empty? " << lq.empty();

	lq.enqueue(1);

	cout << "\nIs the queue empty? " << lq.empty();

}

