#include "util.h"
#include <stdexcept>
#include <iostream>

namespace util
{
	std::string input(const std::string& msg)
	{
		std::string input;
		std::cout << msg;
		std::getline(std::cin, input);
		return input;
	}

	int inputInt(const std::string& msg)
	{
		std::string input;
		int i;
		bool inputting = true;
		while (inputting)
		{
			std::cout << msg;
			std::getline(std::cin, input);

			try
			{
				i = stoi(input);
				inputting = false;
			}
			catch (std::invalid_argument e)
			{
				std::cout << "Invalid input\n";
				inputting = true;
			}
		}

		return i;
	}

	char inputChar(const std::string& msg)
	{
		std::string input;
		bool inputting = true;
		while (inputting)
		{
			std::cout << msg;
			std::getline(std::cin, input);

			if (toupper(input[0]) == 'Y' || toupper(input[0]) == 'N')
				inputting = false;
			else
			{
				std::cout << "Invalid input\n";
				inputting = true;
			}
		}

		return toupper(input[0]);
	}

	bool inputBool(const std::string& msg)
	{
		std::string input;
		bool invalidInput = false;
		bool result = false;
		char ch = '0';

		do
		{
			std::cout << msg;
			std::getline(std::cin, input);

			ch = toupper(input[0]);
			if (!(ch == 'Y') && !(ch == 'N'))
			{
				std::cout << "Invalid input\n";
				invalidInput = true;
			}
			else
				invalidInput = false;
		} while (invalidInput);

		return ch == 'Y';
	}
}