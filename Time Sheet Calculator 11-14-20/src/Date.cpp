
#include "..\headers\Date.h"



Date::Date(int day_value, int month_value, int year_value) : day{ day_value }, month{ month_value }, year{ year_value }
{

}



bool Date::check_date_validity()
{
    if (day > 0 && day <= 31 && month > 0 && month <= 12 && year >= 2020 )
        return true;
    else
    {
        std::cout << "Invalid date entered" << std::endl;
        return false;
    }
}



void Date::reset()
{
    day = 0;
    month = 0;
    year = 0;
}




void Date::construct(int eday, int emonth, int eyear)
{
    day = eday;
    month = emonth;
    year = eyear;
}


void Date::display()
{
    std::cout << day << "/" << month << "/" << year;
}


void Date::write_binary(std::ofstream& o) const
{
    o.write(reinterpret_cast<const char*>(&day), sizeof(day));
    o.write(reinterpret_cast<const char*>(&month), sizeof(month));
    o.write(reinterpret_cast<const char*>(&year), sizeof(year));
}


void Date::read_binary(std::ifstream &i)
{
    i.read(reinterpret_cast<char*>(&day), sizeof(day));
    i.read(reinterpret_cast<char*>(&month), sizeof(month));
    i.read(reinterpret_cast<char*>(&year), sizeof(year));
}


void Date::write_text(std::ofstream& o) const
{
    o << day << "/" << month << "/" << year;
}


int Date::get_day() const
{
    return day;
}

int Date::get_month() const
{
    return month;
}

int Date::get_year() const
{
    return year;
}


bool operator==(const Date& d1, const Date& d2)
{
    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
        return true;
    else
        return false;
}

int operator-(const Date &in, const Date &out)
{
    if (in.day <= out.day && in.month == out.month && in.year == out.year)
    {
        return (out.day - in.day -1);
    }
    else
    {
        std::cout << "Error occured while performing - operation between out and in dates!!!" << std::endl << std::endl;
        return -1;
    }
}