#pragma once

#include "Section.h"
#include "UpperCategories.h"
#include "LowerCategories.h"

class Upper : public Section
{
public:
	Upper()
	{
		categories.push_back(new Ones("Ones"));
	}

	int Tally() override;
private:
};

class Lower : public Section
{
public:
	Lower()
	{
		categories.push_back(new ThreeOfKind("Three of a Kind"));
	};
	void IncrementBonus() { bonus += 100; }
	int Tally() override;
};


