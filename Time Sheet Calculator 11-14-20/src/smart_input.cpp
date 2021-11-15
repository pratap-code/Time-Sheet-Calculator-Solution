
//this defines the functions of the smart_input class

#include "..\headers\smart_input.h"
 


smart_input::smart_input() : xno{ -1 }   // -1 for xno means arbitrary no. of terms and also default value
{
	}


// to get input from the user along with the expected input and expected no. of inputs, inp and xinp has to be entered in the same order
void smart_input::get_input( std::string message, std::string exinp, int& exno )
{
	// prompt to get input from the user    --> just counting in this function
	std::cout << message << " : ";
	getline(std::cin, inp);

	xinp = exinp; // copying the exinp to class member
	xno = exno;

	int count_inp{}, count_xinp{};

	std::stringstream strm;             // to count the no. of words in  input and expected input both and then to verify
	std::string word;

	strm << inp;     // to count the no. of words in input
	strm.clear();
	strm.seekg(0L, std::ios::beg);
	strm.seekp(0L, std::ios::beg);
	while (strm >> word)
	{
		++count_inp;
	}

	word.clear();  // delete the contents of the string word to read words from xinp
	strm.str("");
	strm.clear();
	strm.seekg(0L, std::ios::beg);
	strm.seekp(0L, std::ios::beg);

	strm << xinp;
	strm.clear();
	strm.seekg(0L, std::ios::beg);
	strm.seekp(0L, std::ios::beg);
	while (strm >> word)
	{
		++count_xinp;
	}

	// to check for all the possible number of inputs and if correct then proceed

	if ( count_inp == xno || xno == -1 )    // this method gives more control in different no. of terms in each case
	{
		if (xno == -1)        // if there are arbitrary no. of terms
		{

		}
		else
		{
			if (count_xinp == xno)       // proceed only if there are also correct no. of terms in expected input when xno is not -1
			{

			}
			else
			{
				std::cout << "MISSMATCH in no. of terms in expected input. ERROR!!!" << std::endl;
			}
		}
	}

	

}

// 3. this is all dependent on the entering the correct string in correct order in xinp
// 2. check to see here if parse needs to worry about the case when the xno is -1 or has it been taken care of in get_input
// to process and compare xinp to inp word by word. here one function takes care of processing both inp and xinp
void smart_input::parse()
{
	std::string word_inp,word_xinp;
	std::stringstream stream_inp(inp),stream_xinp(xinp);
	std::vector<std::string>words_inp;
	std::vector<std::string>words_xinp;

	if (xno != -1)  // when there is a fixed no. of terms in the input
	{
		while (stream_inp >> word_inp && stream_xinp >> word_xinp)
		{
			words_inp.push_back(word_inp);
			words_xinp.push_back(word_xinp);
		}


		for (unsigned int i = 0; i < words_xinp.size(); ++i)  // finsih it up
		{
			std::string cur_inp;
			std::string cur_xinp;  // using curr_word here is non-destructing as it works on a copy
			cur_xinp = words_xinp[i];

			cur_inp = words_inp[i];	  // working with the ith word of inp

			cur_xinp.insert(1, " ");  // this inserts space after the first character

			
			size_t pos = cur_xinp.find_first_of("()[]{},");   // find a way to handle strings

			while (pos != std::string::npos)  // make the string space separated here with added spaces where necessary
			{
				cur_xinp.insert((pos + 1), " ");
				pos = cur_xinp.find_first_of("()[]{},");

				if (pos == (cur_xinp.length() - 1))  // this is added to avoid adding space after the last character
					break;
			} // by here a space separated string should be ready


			// declaration of streams and variables needed to extract the limits follows
			std::stringstream cur_word_stm(cur_xinp); //adding current space separated word to stream to process
			char type{}, lb{}, cm{}, rb{};

			cur_word_stm >> type; // first extraction -type

			cur_word_stm >> lb;  // second extraction left bracket

			if (type == 'i') // if type is an integer and also checking if it is only made up of int digits and sign -
			{
				int l{}, r{};

				// extraction of limits with comma

				cur_word_stm >> l; // third extraction left limit

				cur_word_stm >> cm; // fourth extraction comma

				cur_word_stm >> r; // fifth extraction right limit

				cur_word_stm >> rb; // fourth extraction comma


			}
			else if (type == 'd')  // or if it is double
			{
			

			}
			else if (type == 's')  // or if it is a single string word or letter  --> take care of letter
			{

			}
			else  // error case when nothing matches
			{

			}
		
		
		}


	}
	else  // this is the case when there can be arbitrary no. of terms like in strings
	{

	}


	

}



//
void smart_input::split(std::string& cur_word) const
{
	size_t pos = cur_word.find_first_of("([{");

	while (pos != std::string::npos)
	{
		cur_word.insert(pos, " ");
		
		if ( pos == (cur_word.length() - 1) )  // if this is the last character which should be a bracket no need to add a space
			break;

		cur_word.insert( (pos + 2), " " );    // add space both before and after the character
			
		pos = cur_word.find_first_of( ")]}," , (pos+2) );  // start looking after pos+2 or it will keep looping and wrongly			
	}

	// by here the xinp should be separated nicely into a space separated string with space between brackets and nums and commas
	
}


bool smart_input::check_num(std::string& num, char& type) const
{
	if (type == 'i')  // if it is an integer
	{
		if ( ifStrOnly(num, "-0123456789") )    //checking to see if the input is only int characters
		{
			size_t pos = num.find_first_of("-");   // first check if the sign exists or not

			if (pos != std::string::npos)  // if sign exists
			{
				if (pos == 0) // if sign exists and is at the first spot
				{
					pos = num.find_first_of( "-", 1 ); //search the entire string from position 1 on and find out if another -ve sign exists

					if (pos == std::string::npos) // if it doesn't exist then input is a valid int
					{
						std::cout << "Valid int entered!" << std::endl;
						return true;
					}
					else  // if it does exist then pos wil be non zero and hence multiple -ve signs exist!
					{
						std::cout << "ERROR!!! Multiple -ve signs exist in the input!!!" << std::endl;
						return false;
					}

				}
				else // here atleast 1 -ve sign exists but it is not at the beginning
				{
					std::cout << "ERROR!!! INVALID INPUT! sign not at the beggining in int!!!" << std::endl;
					return false;
				}
			}
			else    // if the sign doesn't exist then valid int
			{
				std::cout << "Valid Int entered!" << std::endl;
				return true;
			}

		}
		else
		{
			std::cout << "ERROR!!! Input contains invalid characters that do not make up int!" << std::endl;
			return false;
		}

	}
	else if (type == 'd') // or if is a double
	{
		if ( ifStrOnly(num, "-.0123456789") )  // if the input only consists of valid numbers and dot and -ve sign
		{
			size_t pos_dot = num.find_first_of(".");  // first check if -ve sign exists
			size_t pos_sign = num.find_first_of("-");   // check to see if dot also exists

			if (pos_dot == std::string::npos && pos_sign == std::string::npos)  // if neither the -ve sign nor the dot exist then valid
			{
				std::cout << "Valid double entered!" << std::endl;
				return true;
			}
			else if (pos_dot == std::string::npos && pos_sign != std::string::npos)  // if dot doesn't exists but sign exists
			{
				if (pos_sign == 0) // if sign exists and is at the first position
				{
					pos_sign = num.find_first_of("-", 1); // check to see if another -ve sign exists after 0th pos

					if (pos_sign == std::string::npos)  // if no more -ve sign exists then valid
					{
						std::cout << "Valid double entered!" << std::endl;
						return true;
					}
					else  // atleast 2 -ve signs exist when pos_sign is not npos
					{
						std::cout << "Invalid!! Multiple -ve signs exist!!!" << std::endl;
						return false;
					}
				}
				else // sign not at the first position so invalid
				{
					std::cout << "Invalid! -ve sign not at the beginning in input!" << std::endl;
					return false;
				}
			}
			else if (pos_dot != std::string::npos && pos_sign == std::string::npos)  // if dot exists but -ve sign doesn't  --> if . is at beggining then also add 0 at the beggining
			{
				if (pos_dot == 0) // if . is at beginning then add zero at the beginning
					num.insert(0, "0");

				pos_dot = num.find_first_of(".", (pos_dot + 1));  // start looking for another . from position pos_dot+1

				if (pos_dot == std::string::npos) // if only one . exists then valid
				{
					std::cout << "Valid double entered!";
					return true;
				}
				else // multiple dots exist so invalid
				{
					std::cout << "Invalid!! Multiple dots exist in the input!" << std::endl;
					return false;
				}
			}
			else if (pos_dot != std::string::npos && pos_sign != std::string::npos)  // if both exist  --> also add 0 at the beggining if . is at 2nd place
			{
				if (pos_sign == 0)  // proceed only if the sign is at 0th position
				{
					pos_sign = num.find_first_of("-", 1);  // look for another -ve sign

					if (pos_sign == std::string::npos)   // if another -ve sign doesn't exist 
					{
						if (pos_dot == 1)   // if input is without zero at the beginning of the input
							num.insert(1, "0");

						pos_dot = num.find_first_of(".", (pos_dot + 1));   // look for another dot

						if (pos_dot == std::string::npos)  // if another dot doesn't exist then valid
						{
							std::cout << "Valid double entered!" << std::endl;
							return true;
						}
						else  // another dot exists
						{
							std::cout << "Invalid! Multiple dots exist!" << std::endl;
							return false;
						}

					}
					else  // another -ve sign exists 
					{
						std::cout << "Invalid! Multiple -ve signs exist!" << std::endl;
						return false;
					}
				}
				else    // sign not at the beginning of input so invalid
				{
					std::cout << "Invalid!! sign not at the beginning of input!" << std::endl;
					return false;
				}

			}
			else
			{
				std::cout << "ERROR!!! UNEXPECTED ERROR OCCURED IN 'bool smart_input::check_num(std::string&, char&) const' in 'smart_input.cpp' !!" << std::endl;
				return false;
			}
		}
		else  // if not then not a valid double
		{
			std::cout << "ERROR!!! UNEXPECTED CHARACTERS IN DOUBLE INPUT!" << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "ERROR!!! Unknown error occured in 'bool smart_input::check_num(std::string&, char&) const' in 'smart_input.cpp' !!" << std::endl;
		return false;
	}
}