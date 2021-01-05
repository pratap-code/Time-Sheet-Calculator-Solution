
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
	if (!text_file)
	{
		std::cout << "Error opening " << text_filename <<" for reading!"<<std::endl;
		return;
	}

	binary_file.open(binary_filename.c_str(), std::ios::in | std::ios::binary);
	if (!binary_file)
	{
		std::cout << "Error opening " << binary_filename << " for reading!" << std::endl;
		return;
	}

	Entry text_e;
	Entry binary_e;
	std::vector<Entry>text_records;
	std::vector<Entry>binary_records;

	read_records(text_file, text_e, text_records, "text");
	read_records(binary_file, binary_e, binary_records, "binary");

	if (check_records(text_records, binary_records))
	{
		std::cout << "RECORDS VERIFIED!" << std::endl << std::endl;
		std::cout << "The contents in the time sheet are >>--->" << std::endl;
		display_vector(binary_records);
	}
	else
	{
		std::cout << "FATAL ERROR!!! \t text and binary records do not match!!!" << std::endl;
	}



	text_file.close();
	binary_file.close();

	std::cout << std::endl << std::endl << "FINISHED READING FILES!" << std::endl;

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



std::string tokenize(std::string const& line)
{
	std::string temp(line);
	std::size_t found = temp.find_first_of("*/:~>|");

	if (found == std::string::npos)
		std::cout << "BAD FILE FORMAT!!!" << std::endl;

	while (found != std::string::npos)
	{
		temp[found] = ' ';
		found = temp.find_first_of("*/:~>|",found+1);
	}

	return temp;
}


void read_records(std::ifstream &file, Entry &e,std::vector<Entry>&records,const char* type)
{
	if (type == "text")
	{
		std::string line;
		std::cout << "READING TEXT FILE CONTENTS..." << std::endl;
		while (getline(file,line))
		{
			e.read_text(tokenize(line));
			records.push_back(e);
			e.reset();
			line = "";
		}
	}
	else if (type == "binary")
	{
		std::cout << "READING BINARY FILE CONTENTS... " << std::endl;
		while (true)
		{
			e.read_binary(file);
			if (!file)
			{
				std::cout << "End of binary file reached!" << std::endl;
				break;
			}
			records.push_back(e);
			e.reset();
		}
	}
	else
		std::cout << "Error in READ OPERATION!!!" << std::endl;
}


void display_records(std::vector<Entry>& records, const char* type)
{
	if (type=="text")
	{
		std::cout << "The contents in the text file are : " << std::endl;
			for (unsigned int i = 0; i < records.size(); ++i)
			{
				records[i].display();
			}
	}
	else if (type == "binary")
	{
		std::cout << "The contents in the binary file are : " << std::endl;
		for (unsigned int i = 0; i < records.size(); ++i)
		{
			records[i].display();
		}
	}

}


bool check_records(std::vector<Entry>& text_records, std::vector<Entry>& binary_records)
{
	bool result=false;

	for (size_t i = 0; i < binary_records.size(); ++i)
	{
		if (text_records[i] == binary_records[i])
			result = true;
		else
			result = false;
	}

	return result;
}