#include <iostream>
#include <vector>

#include <algorithm>
#include "Die.h"

#include <gtest\gtest.h>
#include "DieTest.h"
#include "DiceTest.h"

int main()
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}