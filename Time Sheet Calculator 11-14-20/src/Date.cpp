
#include "..\headers\Date.h"



Date::Date(int day_value, int month_value, int year_value) : day{ day_value }, month{ month_value }, year{ year_value }
{

}



bool Date::check_date_validity()
{
    if (day < 0 || day>31 || month < 0 || month>12 || year != 2020)
    {
        std::cout << "Invalid date entered" << std::endl;
        return false;
    }
    else
        return true;
}

void Date::set_date(int dayVal, int monthVal)
{
    day = dayVal;
    month = monthVal;
}


void Date::reset()
{
    day = 0;
    month = 0;
    year = 2020;
}




void Date::construct(int emonth, int eday)
{
    month = emonth;
    day = eday;
}


void Date::display()
{
    std::cout << month << "/" << day << "/" << year;
}


void Date::write_binary(std::ostream& o) const
{
    o.write(reinterpret_cast<const char*>(&day), sizeof(day));
    o.write(reinterpret_cast<const char*>(&month), sizeof(month));
    o.write(reinterpret_cast<const char*>(&year), sizeof(year));
}

void Date::write_text(std::ostream& o) const
{
    o << day << "/" << month << "/" << year;
}

void Date::read_binary(std::string &part)
{
    i.read(reinterpret_cast<char*>(&day), sizeof(day));
    i.read(reinterpret_cast<char*>(&month), sizeof(month));
    i.read(reinterpret_cast<char*>(&year), sizeof(year));
}


void Date::read_text(std::istream& i)
{
    char slash{};
    i >> day >> slash >> month >> slash >> year;
}