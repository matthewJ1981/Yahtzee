#include <algorithm>
#include "Section.h"
#include <assert.h>
#include "categoryEnums.h"

std::vector<std::pair<std::string, int>>  Section::CheckScores(const Dice& dice) const
{
	std::vector<std::pair<std::string, int>> scoringCategories;

	for (int i = 0; i < (int)categories.size(); ++i)
		scoringCategories.push_back({ categories[i]->Name(), categories[i]->CheckScore(dice) });

	return scoringCategories;
}

void Section::SetScore(int index, int score)
{
	assert(index >= 0 && index < (int)categories.size());

	categories[index]->SetScore(score);
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
	std::for_each(categories.begin(), categories.end(), [&](const Category* category) 
		{
			if (category->Score() > -1) temp += category->Score(); 
		});

	subtotal = temp;
}
