

//inclusion of headers

#include "..\headers\Entry.h"



void menu();

int main()
{
	//declaration of variables

	std::cout << std::fixed;    // why?

	std::string choice{ "y" };
	while (choice == "y")
	{
		menu();
		std::cout << std::endl << std::endl << "Do you wish to continue ? ( 'y' for yes) : ";
		getline(std::cin, choice);
	}
	std::cout << std::endl << "Exiting program!!! THANK YOU FOR USING TIME SHEET CALCULATOR BY PRATAP :)" << std::endl;
		
	return 0;
}



// need to create and store multiple files vis a vis binary, text and unformatted text to test and verfiy


