#include "Sections.h"

Upper::Upper()
{
	categories.push_back(new Ones());
	categories.push_back(new Twos());
	categories.push_back(new Threes());
	categories.push_back(new Fours());
	categories.push_back(new Fives());
	categories.push_back(new Sixes());
}

Lower::Lower()
{
	categories.push_back(new ThreeOfKind());
	categories.push_back(new FourOfKind());
	categories.push_back(new FullHouse());
	categories.push_back(new SmallStraight());
	categories.push_back(new LargeStraight());
	categories.push_back(new Yahtzee());
	categories.push_back(new Chance());
}

int Upper::Tally()
{
	CalcSubTotal();
	if (subtotal >= BONUSTHRESHOLD)
		bonus = BONUSVALUE;

	total = subtotal + bonus;
	return total;
}

int Lower::Tally()
{
	CalcSubTotal();
	total = subtotal + bonus;
	return total;
}


// This overridden method exists to enforce scoring options on successive yahtzees
std::vector<std::pair<std::string, int>> Lower::CheckScores(const Dice& dice, const std::vector<std::pair<std::string, int>>& upperScores) const
{
	//Check scores as normal, then check for yahtzee
	std::vector<std::pair<std::string, int>> scores = Section::CheckScores(dice);

	//Assume no yahtzee was rolled.  This will be checked later in setscore()
	SetHasYahtzee(false);

	// Currently rolled a yahtzee
	if (scores[(int)LOWER::YAHTZEE].second == Yahtzee::ScoreValue())
	{
		SetHasYahtzee(true);
		// Already scored a yahtzee so show bonus as scoring option
		if (BonusEligible())
		{
			scores.push_back({ "Bonus", BONUSVALUE });
			IncrementBonus();
		}

		//Force scoring of upper section or allow options of lower per joker rules
		if (categories[(int)LOWER::YAHTZEE]->HasScored())
		{
			//Value of first dice - 1(They are currently all the same value) 
			//to access the index of the appropriate upper category
			int upperIndex = dice[0].Value() - 1;

			//If the upper value has already been scored, the player can choose one of the lower sections to score
			if (upperScores[upperIndex].second == Category::Unscorable())
			{
				if (scores[(int)LOWER::FULLHOUSE].second != Category::Unscorable())
					scores[(int)LOWER::FULLHOUSE].second = FullHouse::ScoreValue();

				if (scores[(int)LOWER::SMALLSTRAIGHT].second != Category::Unscorable())
					scores[(int)LOWER::SMALLSTRAIGHT].second = SmallStraight::ScoreValue();

				if (scores[(int)LOWER::LARGESTRAIGHT].second != Category::Unscorable())
					scores[(int)LOWER::LARGESTRAIGHT].second = LargeStraight::ScoreValue();
			}
			//Otherwise the player must score in the upper section
			else
			{
				scores[(int)LOWER::THREEOFAKIND].second = Category::Unscorable();
				scores[(int)LOWER::FOUROFAKIND].second = Category::Unscorable();
				scores[(int)LOWER::FULLHOUSE].second = Category::Unscorable();
				scores[(int)LOWER::SMALLSTRAIGHT].second = Category::Unscorable();
				scores[(int)LOWER::LARGESTRAIGHT].second = Category::Unscorable();
				scores[(int)LOWER::YAHTZEE].second = Category::Unscorable();
				scores[(int)LOWER::CHANCE].second = Category::Unscorable();
			}
		}
	}


	return scores;
}
