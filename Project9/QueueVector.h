#pragma once
#include "Queue.h"
template <class T>
class QueueVector : public Queue<T>
{
public:
	QueueVector(int max = 100);
	//QueueVector(const QueueVector&);
	void clear() override;
	T dequeue() override;
	void enqueue(T value) override;
	T front() override;
	bool isEmpty() const override;
private:
	T* data;
	int capacity;
	int nextSlot;
	int firstUse;
};
template<class T>
inline QueueVector<T>::QueueVector(int size)
{
	capacity = size + 1;
	data = new T[capacity];
	clear();
}
template<class T>
inline void QueueVector<T>::clear()
{
	nextSlot = 0;
	firstUse = 0;
}

template<class T>
inline T QueueVector<T>::dequeue()
{
	if (isEmpty()) throw "Queue is empty\n";
	int dataloc = firstUse;
	++firstUse %= capacity;
	return data[dataloc];
}
template<class T>
inline void QueueVector<T>::enqueue(T val)
{
	if ((nextSlot + 1) % capacity == firstUse)
		throw "the Queue is full\n";
	data[nextSlot] = val;
	++nextSlot %= capacity;
}
template<class T>
inline T QueueVector<T>::front()
{
	if (isEmpty())
		throw "Queue is empty\n";
	return data[firstUse];
}
template<class T>
inline bool QueueVector<T>::isEmpty() const
{
	return nextSlot == firstUse;
}

