#pragma once

class Die
{
public:
	Die(int sides = 6, int val = 1) : sides(sides), value(val), isHeld(false) {}

	void Roll();

	int Value() const { return value; }
	int Sides() const { return sides; }
	bool IsHeld() const { return isHeld; }
	void SetHeld(int h) { isHeld = h; }
	bool operator< (const Die& rhs) { return value < rhs.value; }
	void SetValue(int v) { value = v; }
private:
	int value;
	int sides;
	bool isHeld;
};

