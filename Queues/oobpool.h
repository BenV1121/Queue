#pragma once

#include <vector>
#include <cassert>

using namespace std;

template <typename T>
class obpool
{
	// Default capacity for object pool.
	const static size_t DEFAULT_POOL_SIZE = 100;

	// Backing array for object pool.
	vector<T> pool;
	vector<bool> poolValidity;

	// Returns the index of the first empty slot found.
	// Returns -1 if an empty index cannot be found.
	size_t nextEmpty()
	{
		for (size_t i; i < poolValidity.size(); ++i)
		{
			if (poolValidity[i] == false)
			{
				return i;
			}
		}
		size_t newIdx = pool.size();

		pool.resize(pool.size * 1.5);
		poolValidity.resize(poolValidity.size() * 1.5);
		memset(&poolValidity[newIdx], 0, sizeof(bool) * newIdx / 2);

		return newIdx = pool.size();
	}
public:
	obpool()
	{
		pool.resize(DEFAULT_POOL_SIZE);
		poolValidity.resize(DEFAULT_POOL_SIZE);

		memset(&pool[0], 0, sizeof(T) * DEFAULT_POOL_SIZE);
		memset(&poolValidity[0], 0, sizeof(T) * DEFAULT_POOL_SIZE);

		/*for (size_t i = 0; i < DEFAULT_POOL_SIZE; ++i)
		{
			pool.push_back(int());
			poolValidity[i] = false;
		}*/

		memset(&poolValidity, 0, sizeof(bool) * DEFAULT_POOL_SIZE);
	}
	~obpool()
	{

	}

	class handle
	{
		// back-pointer to pool
		obpool * pool;

		// index of the object in the pool
		size_t index;
	public:
		handle() : pool(NULL)
		{

		}
		handle(obpool * poolPtr, size_t poolIdx) : pool(poolPtr), index(poolIdx)
		{

		}

		// Returns a reference to the object in the object pool.
		T& value() const
		{
			return pool->at(index);
		}

		// Instructs the object pool to the free the slot occupied by this handle's slot.
		void free()
		{
			pool->pop(index);
		}

		// Returns true if the slot that this handle is referring to is occupied.
		// Otherwise, it should return false.
		bool isValid() const
		{
			return pool->isValid(index);
		}

		// Returns the index of the slot pointed to by this handle.
		T getIndex() const
		{
			return index;
		}
	};

	// Adds the given object to the object pool.
	// Returns a handle with the appropriate information to access the object pool.
	handle push(const T& cpy)
	{
		size_t idx = nextEmpty();
		assert(idx != -1);

		pool[idx] = cpy;
		poolValidity[idx] = true;

		return handle(this, idx);
	}

	// Flags the object at the given index as invalid or unoccupied.
	void pop(size_t idx)
	{
		poolValidity[idx] = false;
	}

	// Returns true if the handle points to a valid object
	bool isValid(size_t idx) const
	{
		return poolValidity[idx];
	}

	// Returns a reference to the object stored in the pool at the given index.
	int& at(size_t idx)
	{
		assert(isValid(idx));
		return pool[idx];
	}
	// Returns a const reference to the object stored in the pool at the given index.
	const int& at(size_t idx) const
	{
		assert(isValid(idx));
		return pool[idx];
	}
};