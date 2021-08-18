	#include "Player.h"
#include "Dice.h"
#include <sstream>
#include <algorithm>

#include "util.h"

Player::Player(std::string n, bool c) : name(n), isComputer(c), rolled(false), rollable(5)
{}

void Player::TakeTurn()
{
	bool playerScored = false;
	rolled = false;
	int currentRoll = 1;

	while (currentRoll <= 3 && playerScored == false)
	{
		std::cout << "Player: " << name << "\n";
		std::cout << "You have " << 4 - currentRoll << " rolls remaining\n\n";
		int choice = -1;


		if (rolled)
		{
			std::cout << "ReadyDice: " << rollable << "\n";
			std::cout << "HeldDice: " << held << "\n\n";

			choice = util::Input("Roll(1), Hold(2), UnHold(3) Score(4), Show scorecard(5), Quit(6): ", 1, 6);
		}
		else
		{
			choice = util::Input("Roll(1), Show scorecard(2), Quit(3): ", 1, 3);
			if (choice == 2)
				choice = 5;
			if (choice == 3)
				choice = 6;
		}

		if (currentRoll == 3 && choice != 4)
			choice = 4;

		switch (choice)
		{
		case 1:
			Roll();
			++currentRoll;
			break;
		case 2:
			Hold();
			break;
		case 3:
			Unhold();
			break;
		case 4:
			playerScored = Score();
			break;
		case 5:
			Print();
			break;
		case 6:
			std::cout << "Need to implement\n";
			break;
		default:
			throw std::runtime_error("Not supposed to get here");
			break;
		}
	}
}

int Player::Roll()
{
	rollable.Roll();
	rolled = true;

	int total = 0;
	for (const auto& d : rollable)
		total += d.Value();
	return total;
}

void Player::Hold()
{
	if (!rolled)
	{
		std::cout << "You need to roll the dice first\n";
		return;
	}

	if (!rollable.empty())
	{
		std::vector<int> diceToMove = GetDiceToMove(rollable);
		MoveDice(rollable, held, diceToMove);
	}
}

void Player::Unhold()
{
	if (!rolled)
	{
		std::cout << "You need to roll the dice first\n";
		return;
	}

	if (!held.empty())
	{
		std::vector<int> diceToMove = GetDiceToMove(held);
		MoveDice(held, rollable, diceToMove);
	}
}

std::vector<int> Player::GetDiceToMove(const Dice& dice) const
{
	std::vector<int> diceToMove;

	std::string msg = "Select which dice to move: \n";
	for (size_t i = 0; i < dice.size(); ++i)
	{
		msg += std::to_string(dice[int(i)].Value()) + " (" + std::to_string(int(i)) + ")\n";
	}
	msg += "\n";

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

bool Player::Score()
{
	if (!rolled)
	{
		std::cout << "You need to roll the dice first\n";
		return false;
	}


	std::cout << "\n*** Scoring options*** \n\n";

	std::vector<std::pair<std::string, int>> scores = scoreCard.CheckScore(rollable + held);

	for (size_t i = 0; i < scores.size(); ++i)
		if (scores[i].second != Category::Unscorable())
			std::cout << i << ": " << scores[i].first << ": " << scores[i].second << "\n";
	std::cout << "\n";

	bool playerScored = false;
	do
	{
		int index = util::Input("Select category to score: ", 0, 12);
		playerScored = scoreCard.SetScore(index, scores[index].second);
		if (!playerScored)
			std::cout << "Category already scored, try again\n\n";
	} while (playerScored == false);

	rollable = rollable + held;
	held.Clear();
	//FIX - Give option to change mind
	return true;
}

void Player::MoveDice(Dice& lhs, Dice& rhs, std::vector<int>& indices)
{
	if (lhs.empty())
		return;

	for (size_t i = 0; i < indices.size(); ++i)
	{
		int adjustedIndex = indices[i] - i;
		rhs.AddDice(lhs[adjustedIndex]);
		lhs.RemoveDice(adjustedIndex);
	}
}

void Player::Print()
{
	std::cout << "Name: " << name << "\n";
	std::cout << scoreCard << "\n\n";
}

std::ostream& operator<<(std::ostream& out, Player& player)
{
	out << "Name: " << player.name << " Score: " << player.scoreCard.Tally();
	
	return out;
}


