#include "Die.h"
#include <cstdlib>

void Die::Roll()
{
	value = rand() % (sides - 1) + 1;
}

std::ostream& operator<<(std::ostream& out, const Die& die)
{
	out << "Value: " << die.value << " Sides: " << die.sides;
	
	return out;
}
