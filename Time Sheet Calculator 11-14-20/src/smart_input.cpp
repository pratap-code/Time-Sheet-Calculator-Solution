
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
