
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

		if (check_records(text_records, binary_records))
		{
			std::cout << "RECORDS VERIFIED!!!" << std::endl;
			
			std::string choice{ "y" };

			while (choice == "y")
			{

				std::cout << "Time Sheet records are loaded!" << std::endl;
				modify_records(text_records, binary_records);
				std::cout << "Do you want to continue editing vector ? : ";
				getline(std::cin, choice);
			}
		}
		else
		{
			std::cout << "FATAL ERROR!!! TEXT AND BINARY RECORDS DO NOT MATCH!!!" << std::endl;
			std::cout << "Now returning to the main menu..." << std::endl;
			return;
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


	std::cout << "NEW RECORDS READY TO SAVE. Do you replace files " << text_filename << " " << binary_filename
		<< " and save modified records ? ( 'y' for yes, any other key for no ) : ";

	std::string choice;
	getline(std::cin, choice);

	if (choice == "y")
	{
		std::cout << "Writing modified data to new files...\n\n";
		write_modified_data(binary_records, text_filename, binary_filename);
	}
	else
	{
		std::cout << "Time Sheet not modified!!\nReturning to the main menu..." << std::endl << std::endl;
		return;
	}






}


void modify_records(std::vector<Entry>&text_records, std::vector<Entry>&binary_records)
{
	
	std::cout << "What would you like to do? : "<<std::endl;
	std::cout << "1. Add entries" << std::endl;
	std::cout << "2. Insert an entry" << std::endl;
	std::cout << "3. Delete an entry" << std::endl;
	std::cout << "4. Modify an entry" << std::endl;

	int choice{ get_int() };

	switch (choice)
	{
		
		case 1:
		{
			std::cout << "##### ADD ENTRIES TO EXISTING TIME SHEET #####" << std::endl << std::endl;

			std::cout << "Currently contained records..." << std::endl;
			display_vector( binary_records );

			std::cout << std::endl;
			std::cout << std::endl;

			std::cout << "Begin entering records..." << std::endl;
			add_records(binary_records);

			std::cout << std::endl;
			std::cout << std::endl;

			std::cout <<"Records after adding records..."<< std::endl;
			display_vector(binary_records);


			break;
		}
	
		case 2:
		{
			std::cout << "+++++ INSERT AN ENTRY +++++" << std::endl << std::endl;
			std::cout << "Enter the serial number where you would like to insert the entry : ";

			int sno{ get_int() };

		
			if ( sno <= 0 || sno > (binary_records.size()+1) )
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

			std::cout << std::endl << "Displaying new vector data for both text and binary :" << std::endl << std::endl;
			
			display_vector(text_records);
			display_vector(binary_records);




			break;
		
		}
		case 3:
		{

			std::cout << "----- Delete an entry -----" << std::endl << std::endl;
			
			std::cout << "Please enter the serial no. of the entry you'd like to delete : ";
			int sno{ get_int() };
			
			std::cout << std::endl << std::endl;
			display_vector(text_records);
			std::cout<<std::endl;
			display_vector(binary_records);
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
		case 4:
		{
			


			break;
		}
		default:
		{
			std::cout << "INVALID CHOICE ENTERED!!! \n Returning to the main menu..." << std::endl;
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



void add_records(std::vector<Entry>&records)
{
	Input input;
	Entry entry;

	
	size_t no = records.size();

	
	std::string choice;
	int stored_day{ records[no - 1].get_Date("day") + 1 };
	int stored_month{ records[no - 1].get_Date("month") };
	int stored_year{ records[no - 1].get_Date("year")  };
	int stored_sno{ records[no-1].get_sno() + 1};

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


void write_modified_data(std::vector<Entry>&records, std::string &text_filename, std::string &binary_filename )
{
	std::ofstream new_text_file;
	std::ofstream new_binary_file;


	new_text_file.open(text_filename.c_str(), std::ios::out | std::ios::trunc);
	new_binary_file.open(binary_filename.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);

	if (records.empty())
	{
		std::cout << "Records are empty...\nReturning to 3. Modify function..." << std::endl;
		return;
	}
	else
	{
		write_to_file(new_text_file, records, "TEXT");
		write_to_file(new_binary_file, records, "BINARY");

		std::cout << "WRITING NEW FILES SUCCESSFULL!!!\nReturning to 3. Modify Time Sheet..." << std::endl;

	}
}