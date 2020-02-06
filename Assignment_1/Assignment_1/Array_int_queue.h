#ifndef ARRAY_INT_QUEUE_H
#define ARRAY_INT_QUEUE_H

#include "Int_queue.h"

class Array_int_queue : public Int_queue {
private:
	int msize; // max size of the queue
	int head; // head pointer
	int tail; // rear pointer
	int *queue; // pointer to the queue array
public:
	void enqueue(int) override;
	void dequeue() override;
	bool empty() override;
	bool full() override;
	Array_int_queue(int);
	~Array_int_queue();
};

#endif //