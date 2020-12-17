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
};

class Lower : public Section
{
public:
	Lower()
	{
		//categories.push_back(new Ones());
	};
};

