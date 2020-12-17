#include "Section.h"

std::vector<std::pair<Category*, int>> Section::CheckScores(const std::vector<Die>& dice)
{
	std::vector<std::pair<Category*, int>> scoringCategories;

	for (Category* category : categories)
	{
		int score = category->CheckScore(dice);
		if (score > -1)
			scoringCategories.push_back(std::make_pair(category, score));
	}

	return scoringCategories;
}