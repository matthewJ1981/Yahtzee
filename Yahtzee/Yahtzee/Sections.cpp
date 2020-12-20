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
	if (subtotal >= 63)
		bonus = 35;

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
std::vector<int> Lower::CheckScores(const Dice& dice, std::vector<int> upperCategories) const
{
	std::vector<int> scores = Section::CheckScores(dice);

	// Currently rolled a yahtzee
	if (scores[5] == 50)
	{
		// Already scored a yahtzee so show bonus as scoring option
		if (categories[5]->Score() == 50)	
			scores.push_back(100);

		//Force scoring of upper section or allow options of lower per joker rules
		if (categories[5]->Score() == 50 || categories[5]->Score() == 0)
		{
			int upperIndex = dice.GetDice()[0].Value() - 1;

			if (upperCategories[upperIndex] == -1)
			{
				if (scores[2] != -1)
					scores[2] = 25;

				if (scores[3] != -1)
					scores[3] = 30;

				if (scores[4] != -1)
					scores[4] = 40;
			}
			else
			{
				scores[0] = -1;
				scores[1] = -1;
				scores[2] = -1;
				scores[3] = -1;
				scores[4] = -1;
				scores[5] = -1;
				scores[6] = -1;
			}
		}
	}

	return scores;
}
