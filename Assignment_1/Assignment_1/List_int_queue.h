#ifndef LIST_INT_QUEUE_H
#define LIST_INT_QUEUE_H

#include "Int_queue.h"
#include <list>

class List_int_queue : public Int_queue {
private:
	int msize; // max size of the queue
	int count; // keeping track of the current number of elements in the queue
	std::list<int> *queue; // pointer to the list, representing the queue
public:
	void enqueue(int) override;
	void dequeue() override;
	bool empty() override;
	bool full() override;
	List_int_queue(int);
	~List_int_queue();
};

#endif
