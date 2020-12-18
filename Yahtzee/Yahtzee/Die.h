#pragma once

class Die
{
public:
	Die(int sides = 6, int val = 1) : sides(sides), value(val) {}

	void Roll();

	int Value() const { return value; }
	int Sides() const { return sides; }

	void SetValue(int v) { value = v; }
private:
	int value;
	int sides;
};

