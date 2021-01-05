#pragma once

#include <gtest/gtest.h>
#include "../Player.h"

class PlayerTest : public testing::Test
{
protected:
	PlayerTest() : player("Fred", true), dice(5) {}
	virtual void SetUp()
	{
		player = Player("Fred", true);
		dice = Dice(5);
		//player = new Player("Fred", true);
	}

	virtual void TearDown()
	{
		//delete player;
	}

	std::string name = "Fred";
	Player player;
	Dice dice;
};

TEST_F(PlayerTest, ConstructorTest)
{
	EXPECT_EQ(player.Name(), name);
	EXPECT_EQ(player.Iscomputer(), true);
}

TEST_F(PlayerTest, TalyTest)
{
	EXPECT_EQ(player.Name(), name);
	EXPECT_EQ(player.Tally(), 0);
	EXPECT_EQ(player.Iscomputer(), true);
}

TEST_F(PlayerTest, SetScoreTest)
{
	player.SetScore(0, dice);
	EXPECT_EQ(player.Name(), name);
	EXPECT_EQ(player.Tally (), 5);
	EXPECT_EQ(player.Iscomputer(), true);
}

TEST_F(PlayerTest, CheckScoreTest)
{
	EXPECT_EQ(player.Name(), name);
	EXPECT_EQ(player.CheckScore(dice)[0], 5);
	EXPECT_EQ(player.Iscomputer(), true);
}

TEST_F(PlayerTest, RollDiceTest)
{
	player.RollDice(dice);
	EXPECT_EQ(player.Name(), name);
	//EXPECT_EQ(player.CheckScore(dice)[0], 0);
	EXPECT_EQ(player.Iscomputer(), true);
}

TEST_F(PlayerTest, HoldDiceTest)
{
	Dice dice2;
	player.HoldDice(dice, dice2, { 0, 1, 2, 3, 4 });
	EXPECT_EQ(dice.size(), 0);
	EXPECT_EQ(dice2.size(), 5);

	EXPECT_EQ(player.Name(), name);
	EXPECT_EQ(player.CheckScore(dice)[0], 0);
	EXPECT_EQ(player.Iscomputer(), true);
}

TEST_F(PlayerTest, UnholdDiceTest)
{
	Dice dice2;
	player.HoldDice(dice, dice2, { 0, 1, 2, 3, 4 });
	player.UnholdDice(dice2, dice, { 0, 1, 2, 3, 4 });
	EXPECT_EQ(dice.size(), 5);
	EXPECT_EQ(dice2.size(), 0);

	EXPECT_EQ(player.Name(), name);
	EXPECT_EQ(player.CheckScore(dice)[0], 5);
	EXPECT_EQ(player.Iscomputer(), true);
}