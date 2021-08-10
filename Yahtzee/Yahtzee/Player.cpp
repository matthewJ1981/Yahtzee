	#include "Player.h"
#include "Dice.h"
#include <sstream>
#include <algorithm>

#include "util.h"

Player::Player(std::string n, bool c) : name(n), isComputer(c)
{}

//std::vector<int> Player::CheckScore(const Dice& dice) const
//{
//	return scoreCard.CheckScore(dice);
//}

void Player::RollDice(Dice& dice) const
{
	dice.Roll();
}

void Player::HoldOrReady(Dice& readyDice, Dice& heldDice)
{
	if (!heldDice.empty())
	{
		if (util::inputBool("Would you like to unhold any dice?"))
		{
			std::vector<int> diceToMove = GetDiceToMove(heldDice);
			UnholdDice(heldDice, readyDice, diceToMove);
		}
	}
	if (!readyDice.empty())
	{
		if (util::inputBool("Would you like to hold any dice?"))
		{
			std::vector<int> diceToMove = GetDiceToMove(readyDice);
			HoldDice(readyDice, heldDice, diceToMove);
		}
	}
}

std::vector<int> Player::GetDiceToMove(const Dice& dice) const
{
	std::vector<int> diceToMove;

	std::string msg = "Select which dice to move: ";
	for (size_t i = 0; i < dice.size(); ++i)
	{
		msg += std::to_string(dice[int(i)].Value()) + " (" + std::to_string(int(i)) + ")";
		if (i < dice.size() - 1)
			msg += " ";
	}

	bool inputting = true;
	while (inputting)
	{
		inputting = false;
		std::string input = util::input(msg);
		std::istringstream ss(input);

		
		int diceNum = -1;
		while (ss >> diceNum)
		{
			bool duplicate = false;
			for(int i : diceToMove)
				if (diceNum == i)
					duplicate = true;

			if (diceNum >= 0 && diceNum < int(dice.size()) && duplicate == false)
			{
				diceToMove.push_back(diceNum);
			}
			else
			{
				diceToMove.clear();
				inputting = true;
			}
		}
	}

	std::sort(diceToMove.begin(), diceToMove.end());

	return diceToMove;
}

//int Player::Tally()
//{
//	return scoreCard.Tally();
//}
//
//std::vector<int> Player::GetScores()
//{
//	return scoreCard.GetScores();
//}

void Player::HoldDice(Dice& dice1, Dice& dice2, std::vector<int> diceToMove)
{
	for (size_t i = 0; i < diceToMove.size(); ++i)
	{
		dice1[diceToMove[i]].SetHeld(true);
	}

	for (size_t i = 0; i < dice1.size(); ++i)
		if (dice1[i].IsHeld())
			dice2.AddDice(dice1[i]);


	for (size_t i = 0; i < dice1.size(); ++i)
	{
		if (dice1[i].IsHeld())
		{
			dice1.RemoveDice(i);
			--i;
		}
	}
}

void Player::UnholdDice(Dice& dice1, Dice& dice2, std::vector<int> diceToMove)
{
	for (size_t i = 0; i < diceToMove.size(); ++i)
	{
		dice1[diceToMove[i]].SetHeld(false);
	}

	for (size_t i = 0; i < dice1.size(); ++i)
		if (!dice1[i].IsHeld())
			dice2.AddDice(dice1[i]);


	for (size_t i = 0; i < dice1.size(); ++i)
	{
		if (!dice1[i].IsHeld())
		{
			dice1.RemoveDice(i);
			--i;
		}
	}
}

//bool Player::SetScore(int index, int score)
//{
//	scoreCard.SetScore(index, score);
//	return true;
//}

std::ostream& operator<<(std::ostream& out, Player& player)
{
	out << "Name: " << player.name << " Score: " << player.scoreCard().Tally();
	
	return out;
}


