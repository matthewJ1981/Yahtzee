#include "ScoreCard.h"

#include <vector>
#include <iterator>

#include "Category.h"

#include <iostream> // temporary. ******************************************************

std::vector<std::tuple<int , int , std::string>> ScoreCard::CheckScore(const Dice& dice) const
{
	// Check scoring options
	std::vector<std::tuple<int, int, std::string>> upperScoringCategories = upper->CheckScores(dice);
	std::vector<std::tuple<int, int, std::string>> lowerScoringCategories = lower->CheckScores(dice);

	std::vector<std::tuple<int, int, std::string>> scoringCategories;
	std::move(upperScoringCategories.begin(), upperScoringCategories.end(), std::back_inserter(scoringCategories));
	std::move(lowerScoringCategories.begin(), lowerScoringCategories.end(), std::back_inserter(scoringCategories));

	return scoringCategories;
	/*
	// Output options
	for (auto category : scoringCategories)
		std::cout << category.first->Name() << ": " << category.second << "\n";

	// Get input option
	int input = 1;
	--input; // subtract 1 to get index in vector;


	// adjust score
	if (input == 0 && input < (int)scoringCategories.size())
	{
		std::pair<Category*, int> selection = scoringCategories[input];
		selection.first->SetScore(selection.second);
	}*/
}

int ScoreCard::Tally()
{
	return upper->Tally() + lower->Tally();
}
