#include "Player.h"
#include "Dice.h"

Player::Player(std::string n) : name(n)
{
	//ResetDice();
}

//void Player::TakeTurn()
//{
//	//readyDice = Dice::YahtzeeDice();
//	//for (int i = 0; i < 3; ++i)
//	//{
//	//	readyDice.Roll(); 
//	//	GetInput();
//	//	//RollDice();
//	//	//HoldDie(2);
//	//	scorecard.CheckScore(readyDice);
//	//}
//
//	//ResetDice();
//}

//void Player::RollDice(Dice& dice)
//{
//	dice.Roll();
//}
//
//bool Player::HoldDie(int die)
//{
//	/*if (die - 1 < 0 || die - 1 > numDice)
//		return false;
//
//	heldDice.push_back(readyDice[die - 1]);
//	readyDice.erase(readyDice.begin() + die - 1);
//
//	for (size_t i = 0; i < readyDice.size(); ++i)
//		std::cout << readyDice[i].Value() << ", ";
//	std::cout << "\n";
//	for (size_t i = 0; i < heldDice.size(); ++i)
//		std::cout << heldDice[i].Value() << ", ";
//	std::cout << "\n";
//
//	return true;*/
//	return true;
//}

//void Player::ResetDice()
//{
//	//readyDice.clear();
//	//heldDice.clear();
//
//	//for (int i = 0; i < numDice; ++i)
//	//	readyDice.push_back({ 6 });
//}

std::vector<int> Player::CheckScore(const Dice& dice) const
{
	return scoreCard.CheckScore(dice);
}

int Player::Tally()
{
	return scoreCard.Tally();
}

void Player::SetScore(int index, const Dice& dice)
{
	scoreCard.SetScore(index, dice);
}

std::vector<int> Player::GetScores()
{
	return scoreCard.GetScores();
}

std::ostream& operator<<(std::ostream& out, Player& player)
{
	out << "Name: " << player.name << " Score: " << player.Tally();
	
	return out;
}
