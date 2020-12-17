#include "Player.h"
#include <iostream> // Temporary *****************************************************

Player::Player(std::string n) : name(n), numDice(5)
{
	ResetDice();
}

void Player::TakeTurn()
{
	std::cout << name << "'s turn\n";
	for (int i = 0; i < 3; ++i)
	{
		RollDice();
		//HoldDie(2);
		scorecard.CheckScore(readyDice);
	}

	ResetDice();
}

void Player::RollDice()
{
	for (size_t i = 0; i < readyDice.size(); ++i)
		readyDice[i].Roll();

	for (size_t i = 0; i < readyDice.size(); ++i)
		std::cout << readyDice[i].Value() << ", ";
	std::cout << "\n";
}

bool Player::HoldDie(int die)
{
	if (die - 1 < 0 || die - 1 > numDice)
		return false;

	heldDice.push_back(readyDice[die - 1]);
	readyDice.erase(readyDice.begin() + die - 1);

	for (size_t i = 0; i < readyDice.size(); ++i)
		std::cout << readyDice[i].Value() << ", ";
	std::cout << "\n";
	for (size_t i = 0; i < heldDice.size(); ++i)
		std::cout << heldDice[i].Value() << ", ";
	std::cout << "\n";

	return true;
}

void Player::ResetDice()
{
	readyDice.clear();
	heldDice.clear();

	for (int i = 0; i < numDice; ++i)
		readyDice.push_back({ 6 });
}