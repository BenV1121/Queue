#pragma once

class obpool
{
	// Default capacity for object pool.
	const static size_t DEFAULT_POOL_SIZE = 100;

	// Backing array for object pool.
	int pool[DEFAULT_POOL_SIZE];
	bool  poolValidity[DEFAULT_POOL_SIZE];

	// Returns the index of the first empty slot found.
	// Returns -1 if an empty index cannot be found.
	size_t nextEmpty();
public:
	obpool();
	~obpool();

	class handle
	{
		// back-pointer to pool
		obpool * pool;

		// index of the object in the pool
		size_t index;
	public:
		handle();
		handle(obpool * poolPtr, size_t poolIdx);

		// Returns a reference to the object in the object pool.
		int& value() const;

		// Instructs the object pool to the free the slot occupied by this handle's slot.
		void free();

		// Returns true if the slot that this handle is referring to is occupied.
		// Otherwise, it should return false.
		bool isValid() const;

		// Returns the index of the slot pointed to by this handle.
		int getIndex() const;
	};

	// Adds the given object to the object pool.
	// Returns a handle with the appropriate information to access the object pool.
	handle push(int cpy);

	// Flags the object at the given index as invalid or unoccupied.
	void pop(size_t idx);

	// Returns true if the handle points to a valid object
	bool isValid(size_t idx) const;

	// Returns a reference to the object stored in the pool at the given index.
	int& at(size_t idx);
	// Returns a const reference to the object stored in the pool at the given index.
	const int& at(size_t idx) const;
};