#include "ScoreCard.h"

#include <vector>
#include <iterator>

#include "Category.h"
#include "categoryEnums.h"

std::vector<std::pair<int , std::string>> ScoreCard::CheckScore(const Dice& dice) const
{
	// Check scoring options
	std::vector<std::pair<int, std::string>> upperScoringCategories = upper.CheckScores(dice);
	std::vector<std::pair<int, std::string>> lowerScoringCategories = lower.CheckScores(dice, upperScoringCategories);

	std::vector<std::pair<int, std::string>> scoringCategories;
	std::move(upperScoringCategories.begin(), upperScoringCategories.end(), std::back_inserter(scoringCategories));
	std::move(lowerScoringCategories.begin(), lowerScoringCategories.end(), std::back_inserter(scoringCategories));

	return scoringCategories;
}

void ScoreCard::SetScore(int index, const Dice& dice)
{
	std::vector<std::pair<int, std::string>> scoringCategories = CheckScore(dice);

	bool test = lower.BonusEligibile();
	if (scoringCategories[(int)ALL::YAHTZEE].first == 50 && lower.BonusEligibile())
		lower.IncrementBonus();

	if (index < 6)
		upper.SetScore(index, scoringCategories[index].first);
	else
		lower.SetScore(index - 6, scoringCategories[index].first);

}

std::vector<std::pair<int, std::string>> ScoreCard::GetScores()
{
	std::vector<std::pair<int, std::string>> upperScores = upper.GetScores();
	std::vector<std::pair<int, std::string>> lowerScores = lower.GetScores();

	std::vector<std::pair<int, std::string>> scores;
	std::move(upperScores.begin(), upperScores.end(), std::back_inserter(scores));
	std::move(lowerScores.begin(), lowerScores.end(), std::back_inserter(scores));

	return scores;
}

int ScoreCard::Tally()
{
	return upper.Tally() + lower.Tally();
}
