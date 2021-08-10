#pragma once
#include <string>
#include <sstream>

namespace util
{
	std::string input(const std::string& msg);
	int inputInt(const std::string& msg);
	char inputChar(const std::string& msg);
	bool inputBool(const std::string& msg);

	/**
	* Common functionality of Input functions
	 */
	template <typename T>
	T InputHelper(std::string msg, T selection, std::ostream& out = std::cout, std::istream& in = std::cin)
	{
		out << msg;
		std::string input = "";
		std::getline(in, input);
		std::stringstream ss(input);
		ss >> selection;

		return selection;
	}

	/**
	 *	Perform some input validation for yes/no input
	 */
	char Input(std::string msg);

	/**
	 *	Perform some input validation for selection within a range
	 */
	template <typename T>
	T Input(std::string msg, T low, T high, std::ostream& out = std::cout, std::istream& in = std::cin)
	{
		T selection(0);

		do
		{
			selection = InputHelper(msg, selection, out, in);
		} while (selection < low || selection > high);

		return selection;
	}
};

