#pragma once

#include <list>

using namespace std;

template <typename T>

// FIFO (first in, first out)
class queue
{
private:
	// What data do I need to store?
	// Are there any helper functions I want?

	list<T> data;

public:
	// Removes the frontmost value.
	// Returns the value that was removed.
	int pop(const T& value)
	{
		T temp = data.front();
		data.pop_front();

		return temp
	}

	// Puts a value on the back of the queue.
	void push(int value)
	{
		data.push_back(value);
	}

	// Returns the frontmost value.
	int front()
	{
		return data.front;
	}

	// Resizes the capacity of the backing array to accommodate
	// the given number of elements.
	void reserve(size_t size);

	// Returns the number of elements.
	size_t size()
	{
		return data.size;
	}

	// Returns true if there are no elements.
	bool empty()
	{
		if (data.size() > 0)
			return true;
		return false;

		return data.size() == 0;

		return data.size();
	}

	// Removes all elements.
	void clear()
	{

	}
};