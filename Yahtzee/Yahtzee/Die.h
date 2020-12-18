#pragma once
#include <cstdlib>
class Die
{
public:
	Die() : sides(6), value(1) {}
	Die(int s) : sides(s), value(1) {}

	void Roll() { value = rand() % (sides - 1) + 1; }

	int Value() const { return value; }
	int Sides() const { return sides; }
private:
	int value;
	int sides;
};

