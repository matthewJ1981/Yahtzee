#pragma once

#include <string>
#include "Dice.h"
#include <iostream>
#include <memory>

class Category
{
public:
	Category(std::string n);
	virtual ~Category() {}
	
	virtual int CheckScore(const Dice& dice) const = 0;
	virtual std::unique_ptr<Category> clone() const = 0;
	inline void SetScore(int s) { score = s; scored = true; }
	inline int Score() const { return score; }
	inline bool Scored() const { return scored; }

	static int Unscorable() { return UNSCORABLE; }
	const std::string& Name() const { return name; }

	int UpperCheckScore(const Dice& dice, int value) const;
	int KindScore(const Dice& dice, int numSame) const;
	bool StraightScore(const Dice& dice, int numConsec) const;

	friend std::ostream& operator << (std::ostream& out, const Category& cat);
protected:

	int score;
	bool scored;
	std::string name;
	static constexpr int UNSCORABLE = -1;
};

