
#include "..\headers\ViewTimeSheet2.h"



void read_time_sheet()
{
	std::ifstream text_file;
	std::ifstream binary_file;
	std::string filename;

	std::cout << "***** 2. View Time Sheet *****" << std::endl << std::endl;
	
	filename = load_file_2();  // to load last loaded or open a custom file

	std::string text_filename = filename + ".txt";
	std::string binary_filename = filename + ".tim";
	
	text_file.open(text_filename.c_str(), std::ios::in);
	binary_file.open(binary_filename.c_str(), std::ios::in | std::ios::binary);

	Entry e;
	std::vector<Entry>records;




	


}

std::string load_file_2()
{
	std::string filename;
	std::cout << "Enter the name of file you want to load or enter 'l' to open last loaded file : ";
	getline(std::cin, filename);

	if (filename == "l")
	{
		std::ifstream file;
		file.open("last_file.txt", std::ios::in);
		file >> filename;
		return filename;
	}
	else
		return filename;
}

