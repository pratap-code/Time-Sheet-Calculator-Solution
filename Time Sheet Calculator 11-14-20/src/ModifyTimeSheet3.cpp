
#include "..\headers\ModifyTimeSheet3.h"

void modify()
{
	std::cout << "*******3. Modify Time Sheet*******" << std::endl;
	std::ifstream text_file;
	std::ifstream binary_file;
	std::string filename;

	Entry text_e;
	Entry binary_e;

	std::vector<Entry>text_records;
	std::vector<Entry>binary_records;

	std::cout << "Enter the name of file you want to modify : ";
	getline(std::cin, filename);
	std::string text_filename = filename + ".txt";
	std::string binary_filename = filename + ".tim";

	text_file.open(text_filename.c_str(), std::ios::in);
	binary_file.open(binary_filename.c_str(), std::ios::in | std::ios::binary);
	
	// read both text and binary records at the same time and check if they opened successfully

	if (text_file && binary_file)
	{
		read_records(text_file, text_e, text_records, "text");
		read_records(binary_file, binary_e, binary_records, "binary");

		std::cout << "Records successfully Loaded!" << std::endl;

		std::string choice{ "y" };

		while (choice == "y")
		{

			modify_records(text_records, binary_records);
			std::cout << "Do you want to continue editing vector ? : ";
			getline(std::cin, choice);
		}





	}
	else
	{
		if (!text_file)
			std::cout << "Error opening text file " << text_filename << "!!!" << std::endl;
		if (!binary_file)
			std::cout << "Error opening binary file " << binary_filename << "!!!" << std::endl;
	}

	text_file.close();
	binary_file.close();





}


void modify_records(std::vector<Entry>&text_records, std::vector<Entry>&binary_records)
{
	std::cout << "What would you like to do? : "<<std::endl;
	std::cout << "1. Insert an entry" << std::endl;
	std::cout << "2. Delete an entry" << std::endl;
	std::cout << "3. Modify an entry" << std::endl;

	int choice{ get_int() };

	switch (choice)
	{
		case 1:
		{
			std::cout << "+++++ INSERT AN ENTRY +++++" << std::endl << std::endl;
			std::cout << "Enter the serial number where you would like to insert the entry : ";

			int sno{ get_int() };

			if (sno<=0 || sno>(binary_records.size()+1))
			{
				std::cout << "Invalid serial no. entered!!!" << std::endl;
				return;
			}

			Entry entry;
			Input input;

			do
			{
				input.reset();
				entry.reset();
				input.get_mod_input();
				input.process_data();
				entry.construct(input);
				entry.set_sno(sno);
			} while (!entry.check_entry_validity());

			insert(text_records, sno, entry);
			insert(binary_records, sno, entry);

			std::cout << "Displaying new vector data for both text and binary :" << std::endl;
			
			display_vector(text_records);
			display_vector(binary_records);




			break;
		
		}
		case 2:
		{
			std::cout << "----- Delete an entry -----" << std::endl << std::endl;
			
			std::cout << "Please enter the serial no. of the entry you'd like to delete : ";
			int sno{ get_int() };
			std::cout << "Delete entry at serial no. " << sno << " ? : ";
			std::string choice;
			getline(std::cin, choice);
			if (choice == "y")
			{
				std::cout << "Deleting entries..." << std::endl;
				delete_rec(text_records, sno);
				delete_rec(binary_records, sno);

				display_vector(text_records);
				display_vector(binary_records);
			}
			else
				std::cout << "Not deleting any entry from records!" << std::endl;

			break;
		}
		case 3:
		{
			


			break;
		}
		default:
		{
			std::cout << "INVALID CHOICE ENTERED!!!" << std::endl;
			break;
		}

	}




}


void insert(std::vector<Entry>&records, int &sno, Entry &entry)
{

	if (sno == (records.size()+1))
		records.push_back(entry);
	else
		records.insert((records.begin()+sno - 1), entry);

	for (unsigned int i = sno; i < records.size(); ++i)
		records[i].mod_sno("insert");

	std::cout << "Entry successfully inserted!" << std::endl;
	
}

void delete_rec(std::vector<Entry>&records, int s)
{
	unsigned int sno = static_cast<unsigned int>(s);
	if (sno < 1||sno>records.size())
	{
		std::cout << "WRONG SERIAL NUMBER ENTERED FOR DELETE OPERATION!!!" << std::endl;
		return;
	}
	
	records.erase(records.begin() + sno - 1);


	for (unsigned int i = (sno-1); i < records.size(); ++i)
	{
		records[i].mod_sno("delete");
	}

	


	std::cout << "Entry deleted successfully!" << std::endl;
}