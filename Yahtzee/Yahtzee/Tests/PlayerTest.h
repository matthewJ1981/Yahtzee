#pragma once

#include <gtest/gtest.h>
#include "../Player.h"

class PlayerTest : public testing::Test
{
protected:

	virtual void SetUp()
	{
		player = new Player("Fred");
	}

	virtual void TearDown()
	{
		delete player;
	}

	std::string name = "Fred";
	Player* player;
	Dice dice;
};

TEST_F(PlayerTest, ConstructorTest)
{
	EXPECT_EQ(player->Name(), name);
}

TEST_F(PlayerTest, TalyTest)
{
	EXPECT_EQ(player->Name(), name);
	EXPECT_EQ(player->Tally(), 0);
}

TEST_F(PlayerTest, SetScoreTest)
{
	player->SetScore(0, dice);
	EXPECT_EQ(player->Name(), name);
	EXPECT_EQ(player->Tally (), 5);
}

TEST_F(PlayerTest, CheckScoreTest)
{
	EXPECT_EQ(player->Name(), name);
	EXPECT_EQ(player->CheckScore(dice)[0], 5);
}