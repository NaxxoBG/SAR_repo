#include "List_int_queue.h"
#include "assert.h"
#include "iostream"

using namespace std;

List_int_queue::List_int_queue(int size) {
	std::list<int> queue(size);
	msize = size;
	count = 0;
}

void List_int_queue::enqueue(int x) {
	if (full())
	{
		cout << "Queue is full, cannot enqueue";
		return;
	}
	queue->push_back(x);
	count += 1;
	
}

void List_int_queue::dequeue() {
	if (queue->empty())
	{
		cout << "Queue is empty, nothing to dequeue";
		return;
	}
	queue->pop_front();
	count -= 1;
};

bool List_int_queue::empty() {
	if (queue->empty()) {
		return true;
	}
	else {
		return false;
	}
};

bool List_int_queue::full() {
	return count == msize;
};

List_int_queue::~List_int_queue() {

};