
//this defines the functions of the smart_input class

#include "..\headers\smart_input.h"


smart_input::smart_input() : xno{ -1 }   // -1 for xno means arbitrary no. of terms and also default value
{
	}


// to get input from the user along with the expected input and expected no. of inputs, inp and xinp has to be entered in the same order
void smart_input::get_input( std::string message, std::string exinp, int& exno )
{
	// prompt to get input from the user
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

	if ( count_inp == xno || xno == -1 )    //not a good idea to check xcount here but later becAuse in case when xno is -1 the if doesn't work right
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


// to parse the xinp string
// the xinp has to follow syntax and also it has to be a space separated string
void smart_input::parse_xinp()
{
	int count{};
	std::string word;
	std::vector<std::string>words;
	std::stringstream strm(xinp);

	//to count the no. of terms in the inp
	while (strm >> word)
	{
		++count;
		words.push_back(word);
	}

	//proceed furthur only if the no. of terms in the input matches the expected no. of terms
	if (xno == count || xno == -1)  // another little check, its fine
	{
		//iterating through  words vector
		for (unsigned int i = 0; i < words.size(); ++i)
		{
			if (words[i].at(0) == 'i')
			{

			}
		}
	}
	else
	{
		std::cout << "Error!!! No. of terms entered doesn't match expected no. of terms!!!" << std::endl;
	}
}

