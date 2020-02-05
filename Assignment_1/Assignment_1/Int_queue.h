
#ifndef INT_QUEUE_H
#define INT_QUEUE_H

class Int_queue {
public:
	virtual void enqueue(int) = 0;
	virtual void dequeue() = 0;
	virtual bool empty() = 0;
	virtual bool full() = 0;
	virtual ~Int_queue() {}
};

#endif // !INT_QUEUE