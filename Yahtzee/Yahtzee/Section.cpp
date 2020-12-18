#include <algorithm>
#include "Section.h"
#include <assert.h>

std::vector<std::tuple<int, int, std::string>> Section::CheckScores(const Dice& dice) const
{
	std::vector<std::tuple<int, int, std::string>> scoringCategories;

	for (int i = 0; i < (int)categories.size(); ++i)
	{
		int score = categories[i]->CheckScore(dice);
		if (score > -1)
			scoringCategories.push_back(std::make_tuple(i, score, categories[i]->Name()));
	}

	return scoringCategories;
}

void Section::SetScore(int index, int score)
{
	assert(index >= 0 && index < (int)categories.size());

	categories[index]->SetScore(score);
}

void Section::CalcSubTotal()
{
	std::for_each(categories.begin(), categories.end(), [this](const Category* category) {subtotal += category->Score(); });
}
