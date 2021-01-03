

#include "..\headers\EnterData1.h"



// function to load a life
std::string load_file()
{


	std::string file_name;

	std::cout << "Which file would you like to load ? " << std::endl;

	std::cout << "1. Load the last opened file" << std::endl;
	std::cout << "2. Create a new file" << std::endl;

	int choice{ get_int() };


	switch (choice)
	{
	case 1:
	{
		std::ifstream file;
		file.open("last_file.txt", std::ios::in);
		getline(file, file_name);
		break;
	}

	case 2:
	{
		std::cout << "What is the name of the file you want to create ? :";
		getline(std::cin, file_name);
		break;
	}

	default:
	{
		std::cout << "Invalid Choice" << std::endl;
		std::cout << "\n Returning to enter data..." << std::endl;
		break;
	}
	}

	return file_name;
}


// function to enter data menu option 1
void enter_data()
{


	std::string filename;

	std::string filename_b, filename_t;

	std::ofstream text_file;
	std::ofstream binary_file;
	Input input;
	Entry entry;

	//vector
	std::vector<Entry>records;




	std::cout << "1. Enter data..." << std::endl;
	filename = load_file();

	filename_b = filename_t = filename;

	open_file(text_file, filename_t, "text");
	open_file(binary_file, filename_b, "binary");

	// inputing entries and verifying and storing them in the vector

	create_vector(input, entry, records);

	display_vector(records);

	

	

	std::string choice;
	std::cout << "Do you want to write the entries to the file? : ";
	
	getline(std::cin, choice);

	if (choice == "y")
	{
		std::cout << "Writing records to files " << filename_t << " and " << filename_b << std::endl;
		
		write_to_file(text_file, records, "TEXT");
		write_to_file(binary_file, records, "BINARY");

		std::cout << "File write successfull..." << std::endl;
	}
	else
		std::cout << "Writing records to files CANCELLED!!!" << std::endl;

	text_file.close();
	binary_file.close();

	


}



void open_file(std::ifstream& file_op, std::string& filename_op, const char* filetype) // open and check file for ifstream for either file types
{

	if (filetype == "text")
	{
		filename_op = filename_op + ".txt";  // add file extension
		file_op.open(filename_op.c_str(), std::ios::in);
	}
	else if (filetype == "binary")
	{
		filename_op = filename_op + ".tim";
		file_op.open(filename_op.c_str(), std::ios::in | std::ios::binary);
	}
	else
		std::cout << "FORMAT ERROR!!!";



	if (!file_op)
		std::cout << "ERROR OPENING FILE!!!" << std::endl;
	else
		std::cout << "File opened successfully..." << std::endl;
}

void open_file(std::ofstream& file_op, std::string& filename_op, const char* filetype) // open and check file for ofstream for either file types
{
	if (filetype == "text")
	{
		filename_op = filename_op + ".txt";
		file_op.open(filename_op.c_str(), std::ios::out | std::ios::app);
	}

	else if (filetype == "binary")
	{
		filename_op = filename_op + ".tim";
		file_op.open(filename_op.c_str(), std::ios::out | std::ios::binary);
	}
	else
		std::cout << "FORMAT ERROR!!!" << std::endl;


	if (!file_op)
		std::cout << "ERROR OPENING FILE!!!" << std::endl;
	else
		std::cout << "File opened successfully" << std::endl;
}


void create_vector(Input& input, Entry& entry, std::vector<Entry>& records)
{
	std::string choice;
	int stored_day{ 0 }, stored_month{ 0 }, stored_sno{ 1 }, stored_year{ 0 };

	do
	{
		do
		{
			int temp_sno{ stored_sno };
			input.reset();
			entry.reset();
			input.get_input( stored_day, stored_month, stored_year );
			input.process_data();
			entry.construct(input);
			entry.set_sno(temp_sno);
		} while (!entry.check_entry_validity());

		records.push_back(entry);

		++stored_sno;
		++stored_day;

		std::cout << "Do you wish to enter more ? ";
		getline(std::cin, choice);
	} while (choice == "y");
}


void write_to_file(std::ofstream& file, std::vector<Entry> &records, const char* FORMAT)
{
	if (FORMAT == "TEXT")
	{
		for (unsigned int i = 0; i < records.size(); ++i)
		{
			records[i].write_text(file);
			if(i<(records.size()-1))
				file << std::endl;
		}
	}

	else if (FORMAT == "BINARY")
	{
		for (unsigned int i = 0; i < records.size(); ++i)
		{
			records[i].write_binary(file);
		}
	}

	else
		std::cout << " ERROR WRITING TO " << FORMAT << " FILE!!!" << std::endl;

}

void display_vector(std::vector<Entry>& records)
{
	std::cout << "The contents in the records are : " << std::endl;
	for (unsigned int i = 0; i < records.size(); ++i)
	{
		records[i].display();
	}
}