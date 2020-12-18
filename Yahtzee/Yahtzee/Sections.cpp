#include "Sections.h"

int Upper::Tally()
{
	if (subtotal >= 63)
		bonus = 35;

	total = subtotal + bonus;
	return total;
}

int Lower::Tally()
{
	total = subtotal + bonus;
	return total;
}