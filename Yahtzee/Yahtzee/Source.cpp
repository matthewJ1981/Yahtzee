#include <iostream>
#include <vector>

#include <algorithm>
#include "Die.h"

#include <gtest\gtest.h>
#include "DieTest.h"
#include "DiceTest.h"

class Category
{
public:
	Category(std::string n) : score(-1), name(n) {}
	virtual ~Category() {}
	int Score() const { return score; }
	virtual int CheckScore(const std::vector<Die>& dice) = 0;
	void SetScore(int s) { score = s; }
	std::string Name() const { return name; }

protected:
	std::string name;
	int score;
};

class Ones : public Category
{
public:
	Ones(std::string n) : Category(n) {}
	int CheckScore(const std::vector<Die>& dice);
private:

};

int Ones::CheckScore(const std::vector<Die>& dice)
{
	if (score > -1)
		return -1;

	int score = 0;
	std::for_each(dice.begin(), dice.end(), [&](const Die& die) {if (die.Value() == 1) ++score; });

	//std::cout << "Score: " << score << "\n";
	//std::cout << "Score: " << this->score << "\n";
	return score;
}

class Section
{
public:
	Section() : subtotal(0), bonus(0), total(0) {}
	virtual ~Section() {};
	const std::vector<Category*> Categories() { return categories; }
	std::vector<std::pair<Category*, int>> CheckScores(const std::vector<Die>& dice);
protected:
	std::vector<Category*> categories;
	int subtotal;
	int bonus;
	int total;
};

std::vector<std::pair<Category*, int>> Section::CheckScores(const std::vector<Die>& dice)
{
	std::vector<std::pair<Category*, int>> scoringCategories;

	for(Category* category : categories)
	{
		int score = category->CheckScore(dice);
		if (score > -1)
			scoringCategories.push_back(std::make_pair(category, score));
	}
	//for (size_t i = 0; i < categories.size(); ++i)
	//{
	//	int score = categories[i]->CheckScore(dice);
	//	if (score > -1)
	//		scoringCategories.push_back(categories[i]);
	//}

	return scoringCategories;

	//std::for_each(categories.begin(), categories.end(), [&](Category* c) {c->CheckScore(dice); });
}

class Upper : public Section
{
public:
	Upper()
	{
		categories.push_back(new Ones("Ones"));
	}
};

class Lower : public Section
{
public:
	Lower()
	{
		//categories.push_back(new Ones());
	};
};

class ScoreCard
{
public:
	ScoreCard() : upper(nullptr), lower(nullptr), total(0)
	{
		upper = new Upper();
		lower = new Lower();
	}
	void CheckScore(const std::vector<Die>& dice);
private:
	//CheckScore();
	//Tally() { total = upper + lower; return total; }
	Section* upper;
	Section* lower;
	int total;
};

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



class Player
{
public:
	Player(std::string n);
	std::string Name() const { return name; }
	void TakeTurn();
	void RollDice();
	bool HoldDie(int die);
	void ResetDice();
private:
	std::string name;
	ScoreCard scorecard;
	std::vector<Die> readyDice;
	std::vector<Die> heldDice;
	int numDice;
};

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

//class Roll
//{
//public:
//	Roll(std::vector<Die>& readyDice, std::vector<Die>& heldDice)
//	{
//		for (int i = 0; i < readyDice.size(); ++i)
//			readyDice[i].Roll();
//
//		for (int i = 0; i < readyDice.size(); ++i)
//			std::cout << readyDice[i].Value() << ", ";
//		std::cout << "\n";
//	}
//
//	Hold();
//	Score();
//
//private:
//};
//
//class Turn
//{
//public:
//	Turn(const Player& p) : player(p)
//	{
//		std::cout << player.Name() << "s Turn\n";
//		for (int i = 0; i < 5; ++i)
//			readyDice.push_back(6);
//
//		for (int i = 0; i < 3; ++i)
//		{
//			Roll(readyDice, heldDice);
//		}
//	}
//private:
//	const Player& player;
//	std::vector<Die> readyDice;
//	std::vector<Die> heldDice;
//
//};
//class Round
//{
//public:
//	Round(const std::vector<Player>& players)
//	{
//		for (int i = 0; i < players.size(); ++i)
//			turns.push_back({ players[i] });
//	}
//private:
//	std::vector<Turn> turns;
//};

class Game
{
public:
	Game()
	{

		
			//rounds.push_back(players);
	}
	void Play()
	{
		for (int i = 0; i < 13; ++i)
			for (size_t j = 0; j < players.size(); ++j)
				players[j].TakeTurn();
	}
	void GetPlayers()
	{
		players.push_back({ "Bob" });
		players.push_back({"Tim"});
	}
private:
	//std::vector<Round> rounds;
	std::vector<Player> players;
};

int main()
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();

	//Game game;
	//game.GetPlayers();
	//game.Play();
	//
	//std::cin.get();
}