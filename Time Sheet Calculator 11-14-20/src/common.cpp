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
	}
	return Choice;
}