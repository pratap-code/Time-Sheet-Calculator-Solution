#include "..\headers\DateTime.h"

// constructor

DateTime::DateTime()
{

}


void DateTime::reset()
{
	date.reset();
	time.reset();
}

bool DateTime::check_DateTime_validity()
{
	if (date.check_date_validity() && time.check_time_validity())
		return true;

	else
		return false;

}


void DateTime::write_text(std::ofstream& o) const
{
	date.write_text(o);
	o << " ~> ";
	time.write_text(o);
}

void DateTime::write_binary(std::ofstream& o) const
{
	date.write_binary(o);
	time.write_binary(o);
}


void DateTime::read_binary(std::ifstream& i)
{
	date.read_binary(i);
	time.read_binary(i);
}


void DateTime::construct(int day, int month, int year, int hour, int min, char ap)
{
	date.construct(day, month, year);
	time.construct(hour, min, ap);
}

void DateTime::display()
{
	date.display();
	std::cout << " ~> ";
	time.display();
}


bool operator==(const DateTime& obj1, const DateTime& obj2)
{
	if (obj1.date == obj2.date && obj1.time == obj2.time)
		return true;
	else
		return false;
}


int DateTime::get_Date(const char* type) const
{
	int value{};
	if (type == "day")
	{
		value = date.get_day();
		return value;
	}
	else if (type == "month")
	{
		value = date.get_month();
		return value;
	}
	else if (type == "year")
	{
		value = date.get_year();
		return value;
	}
	else
	{
		std::cout << "UNEXPECTED BEHAVIOUR AT 'int DateTime::get_Date(const char* type)' in DateTime.cpp!!!" << std::endl;
		return -1;
	}
}


int DateTime::get_Time_num(const char* type) const
{
	int value{};
	
	if (type == "hours")
	{
		value = time.get_hours();
		return value;
	}
	else if (type == "mins")
	{
		value = time.get_mins();
		return value;
	}
	else
	{
		std::cout << "ERROR OCCURED IN `int DateTime::get_Time_num(const char*) const` !!!" << std::endl << std::endl;
		return -1;
	}
}

char DateTime::get_Time_ap() const
{
	char value{};
	value = time.get_ap();
	return value;
}


double DateTime::get_hh(const char * type) const
{
	double result{ time.convert(type) };
	return result;
}