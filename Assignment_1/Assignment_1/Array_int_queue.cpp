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
	tail += 1;
	queue[tail] = x;
}	

void Array_int_queue::dequeue() {
	if (empty())
	{
		return;
	}
	int data = queue[head];
	head = head + 1;
};

bool Array_int_queue::empty() {
	if (head > tail || head < 0) {
		return true;
	}
	else {
		return false;
	}
};

bool Array_int_queue::full() {
	return tail == msize - 1;
};

Array_int_queue::~Array_int_queue() {

};
