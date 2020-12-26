#include "..\headers\Time.h"

Time::Time(int hours_val, int mins_val, char ap_val) : hours{ hours_val }, mins{ mins_val }, ap{ ap_val }
{

}

bool Time::check_time_validity()
{
    if (hours < 0 || hours>12 || mins < 0 || mins>60)
    {
        std::cout << "Invalid time entered " << std::endl;
        return false;
    }
    if (ap != 'a')
    {
        if (ap != 'p')
        {
            std::cout << "Invalid time entered " << std::endl;
            return false;
        }
    }
    return true;
}



void Time::set_time(int hoursVal, int minsVal, char apVal)
{
    hours = hours;
    mins = minsVal;
    ap = apVal;
}



void Time::reset()
{
    hours = mins = 0;
    ap = 'n';
}






//construction of time object from _input data

void Time::construct(int ihours, int imins, char iap)
{
    hours = ihours;
    mins = imins;
    ap = iap;
}

void Time::display()
{
    std::cout << hours << ":" << mins << " " << ap;
}


void Time::write_text(std::ofstream& o) const
{
    o << hours << ":" << mins << " " << ap;
}


void Time::write_binary(std::ofstream& o) const
{
    o.write(reinterpret_cast<const char*>(&hours), sizeof(hours));
    o.write(reinterpret_cast<const char*>(&mins), sizeof(mins));
    o.write(reinterpret_cast<const char*>(&ap), sizeof(ap));
}



void Time::read_binary(std::ifstream& i)
{
    i.read(reinterpret_cast<char*>(&hours), sizeof(hours));
    i.read(reinterpret_cast<char*>(&mins), sizeof(mins));
    i.read(reinterpret_cast<char*>(&ap), sizeof(ap));
}



bool operator==(const Time& t1, const Time& t2)
{
    if (t1.hours == t2.hours && t1.mins == t2.mins && t1.ap == t2.ap)
        return true;
    else
        return false;
}