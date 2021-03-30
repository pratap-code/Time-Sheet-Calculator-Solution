
#include "..\headers\common.h"
#include "..\headers\fixed.h"


fixed::fixed() : value{ 0 }, n{ 0 }
{

}


double fixed::get() const
{
	double val{};
	val = (static_cast<double>(value)) / (10^n);
	return val;
}

void fixed::set()
{
	std::string inp;
	getline(std::cin, inp);
	std::stringstream sstr(parse(inp));

	std::vector<std::string>words;
	std::string word;
	std::stringstream temp(sstr.str()); // to detect sign by counting number of words
	int count{};
	while (temp >> word)
	{
		++count;
		words.push_back(word);
	}

	if (count == 1)
	{
		sstr >> value;
		n = 0;
	}
	else if (count == 2)
	{
		if (words[0] == "-")
		{
			char sign{};
			sstr >> sign >> value;
			value = -value;
			n = 0;
		}
		else // proceed for +ve decimal number
		{
			size_t places{};
			places = words[1].length();
			n = places;
			
			int w{}, d{};
			sstr >> w >> d;

			value = (w * (10 ^ n)) + d;
		}
	}
	else if (count == 3)
	{
		char sign{};
		int w{}, d{};

		sstr >> sign >> w >> d;

		size_t places{};
		places = words[2].length();
		n = places;

		value = -((w * (10 ^ n)) + d);
	}
	else
	{
		std::cout << "ERROR OCCURED IN 'void fixed::set() in fixed.cpp'!!!" << std::endl;
		value = -9999999;
	}





	//if (count == 1)
	//{
	//	int w{};
	//	sstr >> w;
	//	value = w * 100;
	//}
	//else if (count == 2 || count == 3)
	//{
	//	temp.clear();
	//	temp.seekg(0L, std::ios::beg);
	//	word.clear();
	//	std::vector<std::string>words;
	//	while (temp >> word)
	//	{
	//		words.push_back(word);
	//	}
	//
	//	if (words[0] == "-")
	//	{
	//		if (count == 2)
	//		{
	//			char sign{};
	//			int w{};
	//			sstr >> sign >> w;
	//			value = -(w * 100);
	//		}
	//		else
	//		{
	//			char sign{ 'z' };
	//			int w{}, d{};
	//			sstr >> sign >> w >> d;
	//			value = -(w * 100 + d);
	//		}
	//	}
	//	else
	//	{
	//		int w{}, d{};
	//		sstr >> w >> d;
	//		value = (w * 100 ) + d;
	//	}
	//	
	//}
	//else
	//{
	//	std::cout << "ERROR OCCURED IN 'void fixed::set()' in 'fixed.cpp' !!!" << std::endl;
	//	value = -9999999;
	//}
}

std::string fixed::parse(std::string &inp) const
{
	std::string tmp(inp);
	
	//to count and detect - negative
	//std::stringstream stm(inp);
	//std::vector<std::string>words;
	//std::string word;
	//int count{};
	//
	//while (stm >> word)
	//{
	//	words.push_back(word);
	//	++count;
	//}
	
	//if (words[0] == "-")

	size_t found = tmp.find_first_of("-.");
	
	while (found != std::string::npos)
	{
		if (tmp[found] == '-')
		{
			tmp.insert( (found + 1), " " );
		}
		else
			tmp[found] = ' ';
		
		found = tmp.find_first_of(".");
		
	}

	return tmp;
}

void fixed::display() const
{
	std::cout << value << std::endl;
}