
#include "..\headers\common.h"
#include "..\headers\fixed.h"


fixed::fixed() : value{ 0 }, n{ 0 }
{

}


double fixed::get() const
{
	double val{};
	val = (static_cast<double>(value)) / pow(10, n);
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

			value = (w * pow(10 , n)) + d;
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

		value = -((w * pow(10, n)) + d);
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




void fixed::set(std::string& parsed_str) // ovderload for fixed::create()
{

	std::stringstream sstr(parsed_str);
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

			value = (w * pow(10, n)) + d;
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

		value = -((w * pow(10, n)) + d);
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
	std::cout <<"Displaying fixed data : "<< value <<" -> "<< n << std::endl;
}

void fixed::create(double num)
{
	//if (num < 0.0)
	//{
	//	num = num - 0.5;
	//	value = static_cast<int>(num);		//may need to think about the limits here
	//}
	//else if (num > 0.0)
	//{
	//	num = num + 0.5;
	//	value = static_cast<int>(num);
	//}
	//else if (num == 0.0)
	//{
	//	value = 0;
	//}
	//else
	//{
	//	std::cout << "ERROR OCCURED IN 'void fixed::create()' in 'fixec.cpp'!!!" << std::endl;
	//}

	std::stringstream data;
	data << num;

	std::string str;

	data.clear();
	data.seekg(0L, std::ios::beg);

	data >> str;

	std::string parsed_str = parse(str);
	set(parsed_str);



}



void fixed::set_round(std::string &parsed_str) // ovderload for fixed::create() tp
{
	std::stringstream sstr(parsed_str);
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
	
			value = (w * pow(10, n)) + d;
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
	
		value = -((w * pow(10, n)) + d);
	}
	else
	{
		std::cout << "ERROR OCCURED IN 'void fixed::set() in fixed.cpp'!!!" << std::endl;
		value = -9999999;
	}
}



void round(std::string dec)
{
	//size_t l{};
	//l = dec.length();

	//if (l >= 3)
	//{
	//	std::stringstream digit;
	//	int third{};
	//	digit << dec[3];
	//	digit.clear();
	//	digit.seekp(0L, std::ios::beg);
	//	digit >> third;
	//	if (third >= 5)
	//	{
	//		digit.str("");
	//		digit.clear();
	//		digit.seekg(0L, std::ios::beg);
	//
	//		digit << dec[2];
	//
	//
	//		digit.seekg(0L, std::ios::beg);
	//
	//	}
	//}

	std::stringstream decstm;
	decstm << dec;

	size_t count = dec.length();

	if (count == 0)
	{

	}
	else if (count == 1)
	{
		dec.push_back('0');
	}
	else if (count == 2)
	{

	}
	else if (count >= 3)
	{
		std::string temp;
		
		if(dec[2]=='5'|| dec[2] == '6' || dec[2] == '7' || dec[2] == '8' || dec[2] == '9')
		{ 
			std::stringstream stm;
			stm << dec[0] << dec[1];
			int num{};

		}

	}



	

}