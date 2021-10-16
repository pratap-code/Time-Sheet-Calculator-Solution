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
		return -99999;  // if error
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



bool ifStrOnly(std::string str1, const char* str2)  // to see if str1 contains members only of str2
{
	if (str1.find_first_not_of(str2) == std::string::npos)
		return true;
	else
		return false;
}


//this function has conventions for xinput that is the expected no of inputs
//this is very powerful!! continue this later!
void smartt_input(std::string input, std::string xinput, int xno) // continue this later
{
	int count{};
	std::string word;
	std::vector<std::string>words;
	std::stringstream sstr(input);

	//to count the no. of words in input and separate and store them in a vector
	while (sstr >> word)
	{
		++count;
		words.push_back(word);
	}

	// need to add a case for if xno is -1 here
	if (count == xno || xno == -1) // checking to see if the no. if terms in input is equal to the expected no. of terms and if so then proceed
	{

	}
	else
	{
		std::cout << "ERROR! Input contains incorrect no. of terms!!!" << std::endl;
	}

}