#pragma once

#include "Section.h"
#include "UpperCategories.h"

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
		//categories.push_back(new Ones());
	};
	int Tally() override;
};

