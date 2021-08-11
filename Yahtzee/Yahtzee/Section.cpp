#include <algorithm>
#include "Section.h"
#include <assert.h>
#include "categoryEnums.h"

Section::Section(const Section& rhs) : subtotal(rhs.subtotal), bonus(rhs.bonus), total(rhs.total)
{
	if (this != &rhs)
	{
		for (auto& cat : rhs.categories)
			categories.push_back(cat->clone());
	}
}

Section& Section::operator= (const Section& rhs)
{
	if (this != &rhs)
	{
		subtotal = rhs.subtotal;
		bonus = rhs.bonus;
		total = rhs.total;
		categories.clear();
		for (auto& cat : rhs.categories)
			categories.push_back(cat->clone());
	}
	return *this;
}

std::vector<std::pair<std::string, int>> Section::CheckScores(const Dice& dice) const
{
	std::vector<std::pair<std::string, int>> scoringCategories;

	for (int i = 0; i < (int)categories.size(); ++i)
		scoringCategories.push_back({ categories[i]->Name(), categories[i]->CheckScore(dice) });

	return scoringCategories;
}

bool Section::SetScore(int index, int score)
{
	assert(index >= 0 && index < (int)categories.size());

	if (categories[index]->Scored())
		return false;

	categories[index]->SetScore(score);
		return true;
}

std::vector<int> Section::GetScores() const
{
	std::vector<int> scoringCategories;

	for (int i = 0; i < (int)categories.size(); ++i)
		scoringCategories.push_back(categories[i]->Score());

	return scoringCategories;
}

void Section::CalcSubTotal()
{
	int temp = 0;
	std::for_each(categories.begin(), categories.end(), [&](const std::unique_ptr<Category>& category) 
		{
			if (category->Score() > -1) temp += category->Score(); 
		});

	subtotal = temp;
}
