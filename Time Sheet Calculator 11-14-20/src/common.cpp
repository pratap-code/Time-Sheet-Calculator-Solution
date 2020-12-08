#include "..\headers\common.h"

int get_text(std::string& text)
{
	getline(std::cin, text);
	std::stringstream word(text);
	int Choice{ 0 };
	if (!(word >> Choice))
	{
		std::cout << "Invalid option entered..." << std::endl;
	}
	return Choice;
}