#include "Die.h"
#include <cstdlib>

void Die::Roll()
{
	value = rand() % (sides - 1) + 1;
}