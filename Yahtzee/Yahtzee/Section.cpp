#include <algorithm>
#include "Section.h"
#include <assert.h>
#include "categoryEnums.h"

std::vector<std::pair<int, std::string>> Section::CheckScores(const Dice& dice) const
{
	std::vector<std::pair<int,std::string>> scoringCategories;

	for (int i = 0; i < (int)categories.size(); ++i)
		scoringCategories.push_back(std::make_pair(categories[i]->CheckScore(dice), categories[i]->Name()));

	return scoringCategories;
}

void Section::SetScore(int index, int score)
{
	assert(index >= 0 && index < (int)categories.size());

	categories[index]->SetScore(score);
}

std::vector<std::pair<int, std::string>> Section::GetScores()
{
	std::vector<std::pair<int, std::string>> scoringCategories;

	for (int i = 0; i < (int)categories.size(); ++i)
		scoringCategories.push_back(std::make_pair(categories[i]->Score(), categories[i]->Name()));

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
