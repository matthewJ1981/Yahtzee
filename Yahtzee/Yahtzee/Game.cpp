#include "Game.h"
#include "ScoreCard.h"

Game::Game() :
	roundCount(13),
	playing(true),
	currentRound(1),
	currentPlayer(0)
{
}

void Game::Input()
{
	if (state == ROLLING)
	{

	}
	else if (state == ROLLED)
	{
		//After dice roll, choose hold[1] or score[2]
		int input = 1;

		if (input == 1)
		{
			state = HOLD;
			diceToHold.push_back(2);
			diceToHold.push_back(3);
		}
		else
		{
			state = SCORE;
		}
	}
	else if (state == HOLD)
	{

	}
	else
	{

	}
}

void Game::Update()
{

	if (state == ROLLING)
	{
		ResetDice();
		players[currentPlayer].RollDice(readyDice);
		players[currentPlayer].CheckScore();
		//std::cout << players[j].Name() << "'s turn.\n";
		//players[j].TakeTurn();
		state = ROLLED;
	}
	else if (state == HOLD)
	{
		
	}
	else
	{
		currentRound++;
	}
}

void Game::Draw()
{
	if (state == ROLLED)
	{
		std::cout << "ReadyDice: " << readyDice << "\n";
		std::cout << "HeldDice: " << heldDice << "\n";

		std::cout << "Choose dice to hold[1] or score[2]";
	}
	else if (state == HOLD)
	{
		std::cout << "Enter the numbers of the dice to hold: ";
	}
	else
	{

	}
}

bool Game::GameOver()
{
	//evaluate score and determine winner
	return currentRound > 13; // temporary
}
void Game::GetPlayers()
{
	players.push_back({ "Bob" });
	players.push_back({ "Tim" });
}
void Game::ResetDice()
{
	readyDice = Dice::YahtzeeDice();
	heldDice.Clear();
}