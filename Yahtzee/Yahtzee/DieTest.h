#pragma once

#include <gtest/gtest.h>
#include "Die.h"

TEST(DieTest, DefaultTest)
{
	Die die(6);
	EXPECT_EQ(6, die.Sides());
	EXPECT_EQ(1, die.Value());
}

TEST(DieTest, RollTest)
{
	Die die(6);
	die.Roll();
	EXPECT_EQ(6, die.Sides());
	EXPECT_GE(die.Value(), 1);
	EXPECT_LE(die.Value(), 6);
}
