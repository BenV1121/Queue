#include "queue.h"
#include "oobpool.h"
#include <cassert>
#include <iostream>

using namespace std;

void main()
{
	obpool<int> pool;

	obpool<int>::handle han = pool.push(5);
	assert(han.value == 5);
	assert(han.isValid());

	obpool<int>::handle han2 = pool.push(3);
	assert(han2.value() == 3);
	assert(han2.isValid());

	han.free();
	assert(!han.isValid());

	for (size_t i = 0; i < 150; ++i)
	{
		pool.push(rand() % 100);
	}

	cout << pool.at(115) << endl;

	system("pause");
}