#include "..\headers\common.h"

int get_int()
{
	std::string input_choice;
	getline(std::cin, input_choice);
	std::stringstream word(input_choice);
	int Choice{ 0 };
	if (!(word >> Choice))
	{
		std::cout << "Invalid option entered..." << std::endl;
		return -99999;
	}
	return Choice;
}


double get_double()
{
	std::string input;
	getline(std::cin, input);
	std::stringstream word(input);
	double value{};
	if (!(word >> value))
	{
		std::cout << "ERROR OCCURED WHILE GETTING DOUBLE VALUE!!!" << std::endl;
		return -999999.9;
	}
	return value;
}