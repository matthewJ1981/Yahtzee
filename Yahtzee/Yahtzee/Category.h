#pragma once

#include <string>
#include "Dice.h"

class Category
{
public:
	Category() : score(-1) {}
	virtual ~Category() {}
	
	virtual int CheckScore(const Dice& dice) const = 0;

	inline void SetScore(int s) { score = s; }
	inline int Score() const { return score; }
	inline bool HasScored() const { return score > -1; }
	inline bool ScoredZero() const { return score == 0; }

	static int Unscorable() { return UNSCORABLE; }
	static int Scorable() { return SCORABLE; }

protected:
	int score;
	static constexpr int UNSCORABLE = -1;
	static constexpr int SCORABLE = -1;
};

