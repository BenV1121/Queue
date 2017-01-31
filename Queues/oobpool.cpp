#include "oobpool.h"

size_t obpool::nextEmpty()
{
	return size_t();
}

obpool::obpool()
{

}

obpool::~obpool()
{

}

void obpool::pop(size_t idx)
{

}

bool obpool::isValid(size_t idx) const
{
	return false;
}

obpool::handle::handle()
{

}

obpool::handle::handle(obpool * poolPtr, size_t poolIdx)
{

}

int & obpool::handle::value() const
{
	// TODO: insert return statement here
}

void obpool::handle::free()
{

}

bool obpool::handle::isValid() const
{
	return false;
}

int obpool::handle::getIndex() const
{
	return 0;
}
