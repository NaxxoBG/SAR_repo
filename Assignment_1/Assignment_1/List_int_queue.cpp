#include "List_int_queue.h"
#include "assert.h"
#include "iostream"

using namespace std;

List_int_queue::List_int_queue(int size) {
	std::list<int> queue(size);
	msize = size; // setting msize to size so we could use it in the full() function body
	count = 0; // set count to 0 for a newly instantiated queue
}

void List_int_queue::enqueue(int x) {
	if (full())
	{
		cout << "Queue is full, cannot enqueue";
		return;
	}
	// Pushing to the back.
	queue->push_back(x);
	count += 1; // increase element count in the list
	
}

void List_int_queue::dequeue() {
	if (empty())
	{
		cout << "Queue is empty, nothing to dequeue";
		return;
	}
	queue->pop_front(); // removing the element at the front of the queue
	count -= 1; // reducing the number of elements in the list by 1
};

bool List_int_queue::empty() {
	if (count == 0) { // use the builtin empty() function
		return true;
	}
	else {
		return false;
	}
};

bool List_int_queue::full() {
	return count == msize; // just check whether the number of elements is equal to the msize passed during queue initialization
};

List_int_queue::~List_int_queue() {

};