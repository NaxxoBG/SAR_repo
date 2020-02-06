#include "Array_int_queue.h"
#include "assert.h"

Array_int_queue::Array_int_queue(int size) {
	msize = size;
	queue = new int[msize];
	head = 0;
	tail = -1;
}

void Array_int_queue::enqueue(int x) {
	if (full())
	{
		return;
	}
	tail += 1; // increment tail pointer
	queue[tail] = x; // add to the tail
}	

void Array_int_queue::dequeue() {
	if (empty())
	{
		return;
	}
	int data = queue[head]; 
	head = head + 1; // add 1 to the head pointer to remove the access to the var at index head
};

bool Array_int_queue::empty() {
	if (head > tail || head < 0) { // if head is greater than tail that means we have done more dequeues than enqueues, hence empty
		return true;
	}
	else {
		return false;
	}
};

bool Array_int_queue::full() {
	return tail == msize - 1; // because tail starts from -1 in order for the first enqueued element to be at index 0, we subtract 1 from the msize
};

Array_int_queue::~Array_int_queue() {

};
