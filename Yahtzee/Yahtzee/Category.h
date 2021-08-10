#pragma once

#include <string>
#include "Dice.h"

class Category
{
public:
	//THe initial value of -1 is to indicate the category has not been scored.
	//The constexpr UNSCORABLE is to avoid confusion when checkscore wants to return -1 to indicate
	//the category has previously been scored and cannot be scored again.
	Category(std::string n);
	virtual ~Category() {}
	
	virtual int CheckScore(const Dice& dice) const = 0;

	inline void SetScore(int s) { score = s; }
	inline int Score() const { return score; }
	inline bool HasScored() const { return score > -1; }
	inline bool ScoredZero() const { return score == 0; }

	static int Unscorable() { return UNSCORABLE; }
	const std::string& Name() const { return name; }

	int UpperCheckScore(const Dice& dice, int value) const;
protected:

	int score;
	std::string name;
	static constexpr int UNSCORABLE = -1;
};

