
#include<iostream>

#include "..\headers\common.h"
#include "..\headers\EnterData1.h"
#include "..\headers\ViewTimeSheet2.h"
#include "..\headers\ModifyTimeSheet3.h"


void menu();





//still to finish
void menu()
{

	std::cout << "******************TIME SHEET CALCULATOR******************" << std::endl << std::endl;


	{
		std::cout << "What would you like to do : " << std::endl;
		std::cout << "1. Enter time sheet data" << std::endl;
		std::cout << "2. View time sheet" << std::endl;
		std::cout << "3. Modify time sheet" << std::endl;
		std::cout << "4. Delete a time sheet file" << std::endl;
		std::cout << "5. Calculate time and pay" << std::endl;
		std::cout << "6. Load a new file" << std::endl;
		std::cout << "7. Exit" << std::endl;
	}


	int choice{ get_int() };




	switch (choice)
	{
	case 1:
	{
		std::cout << "To create new file" << std::endl;
		enter_data();
		break;
	}
	case 2:
	{
		read_time_sheet();
		break;
	}
	case 3:
	{
		modify();
		break;
	}

	default:
	{
		std::cout << "INVALID" << std::endl;
		break;
	}
	}
}

