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
	}

	virtual void TearDown()
	{
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

TEST_F(PlayerTest, TallyTest)
{
	EXPECT_EQ(player.Name(), name);
	EXPECT_EQ(player.Tally(), 0);
	EXPECT_EQ(player.Iscomputer(), true);
}
