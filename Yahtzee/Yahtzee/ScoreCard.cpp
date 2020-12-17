#include "ScoreCard.h"

#include <vector>
#include <iterator>

#include "Category.h"

#include <iostream> // temporary. ******************************************************
void ScoreCard::CheckScore(const std::vector<Die>& dice)
{
	// Check scoring options
	std::vector<std::pair<Category*, int>>upperScoringCategories = upper->CheckScores(dice);
	std::vector<std::pair<Category*, int>> lowerScoringCategories = lower->CheckScores(dice);

	std::vector<std::pair<Category*, int>> scoringCategories;
	std::move(upperScoringCategories.begin(), upperScoringCategories.end(), std::back_inserter(scoringCategories));
	std::move(lowerScoringCategories.begin(), lowerScoringCategories.end(), std::back_inserter(scoringCategories));

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
	}
}