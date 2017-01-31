#include "queue.h"
#include "oobpool.h"
#include <cassert>
#include <iostream>

using namespace std;

void main()
{
	obpool<int> pool;

	obpool<int>::handle han = pool.push(3);
	assert(han.value == 3);
	assert(han.isValid());

	obpool<int>::handle han2 = pool.push(5);
	assert(han2.value() == 5);
	assert(han2.isValid());

	obpool<int>::handle han3 = pool.push(7);
	assert(han3.value() == 7);
	assert(han3.isValid());

	obpool<int>::handle han4 = pool.push(9);
	assert(han4.value() == 7);
	assert(han4.isValid());

	han3.free();

	int expected[] = { 3, 5, 9 };

	size_t i = 0;

	for (auto iter = pool.begin(); iter != pool.end(); ++iter)
	{
		int val = *iter;
		assert(expected[i] == val);
		i++;
	}

	/*han.free();
	assert(!han.isValid());

	for (size_t i = 0; i < 150; ++i)
	{
		pool.push(rand() % 100);
	}

	cout << pool.at(115) << endl;*/

	system("pause");
}