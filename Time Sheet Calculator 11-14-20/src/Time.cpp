#include "..\headers\Time.h"

Time::Time(int hours_val, int mins_val, char ap_val) : hours{ hours_val }, mins{ mins_val }, ap{ ap_val }
{

}

bool Time::check_time_validity()
{
    bool result{};
    if (hours > 0 && hours <= 12 && mins >= 0 && mins < 60)
    {
        if (ap == 'a' || ap == 'p')
            result = true;
        else
            result = false;
    }

    else
        result = false;

    if (!result)
        std::cout << "INVALID TIME ENTERED!!!" << std::endl;

    return result;
}



void Time::set_time(int hoursVal, int minsVal, char apVal) // maybe not used anywhere, need to get rid of
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

void Time::display() const  // displays time object in formatted format
{
    std::cout << hours << ":" << mins << " " << ap;
}


void Time::write_text(std::ofstream& o) const // to write the time object in formatted text format
{
    o << hours << ":" << mins << " " << ap;
}


void Time::write_binary(std::ofstream& o) const // to write time object in binary format
{
    o.write(reinterpret_cast<const char*>(&hours), sizeof(hours));
    o.write(reinterpret_cast<const char*>(&mins), sizeof(mins));
    o.write(reinterpret_cast<const char*>(&ap), sizeof(ap));
}



void Time::read_binary(std::ifstream& i)  // to read time object from binary file
{
    i.read(reinterpret_cast<char*>(&hours), sizeof(hours));
    i.read(reinterpret_cast<char*>(&mins), sizeof(mins));
    i.read(reinterpret_cast<char*>(&ap), sizeof(ap));
}



bool operator==(const Time& t1, const Time& t2)  // to check if two times are equal
{
    if (t1.hours == t2.hours && t1.mins == t2.mins && t1.ap == t2.ap)
        return true;
    else
        return false;
}




// getters
int Time::get_hours() const
{
    return hours;
}

int Time::get_mins() const
{
    return mins;
}

char Time::get_ap() const
{
    return ap;
}



// MAYBE NEED TO WRITE THIS AGAIN WHERE IT CALCULATES THE TOTAL DIFFERENCE BY CALCULATING TOTAL MINS FIRST
// AND THEN CALCULATE THE DIFFERENCE
// to convert time to 24 hr format -----> this is needed to calculate the differences in time 
double Time::convert(const char* type) const   // type is in or out meaning in time or out time
{
    double result{};

    if (hours == 12)
    {
        if (ap == 'p')
        {
            result = 12.0 + ((static_cast<double>(mins) / 60.0));
        }
        else if (ap == 'a')
        {
            if (mins == 0)
            {
                if (type == "in")
                {
                    result = 0.0;
                }
                else if (type == "out")
                {
                    result = 24.0;
                }
                else
                {
                    result = -1.0;
                }

            }
            else
            {
                result = (static_cast<double>(mins) / 60.0);
            }
        }
        else
        {
            result = -1.0;
        }
    }
    else
    {
        if (ap == 'a')
        {
            result = (static_cast<double>(hours)) + ((static_cast<double>(mins)) / 60.0) ;
        }
        else if (ap == 'p')
        {
            result = (static_cast<double>(hours)) + 12.0 + ((static_cast<double>(mins)) / 60.0);
        }
        else                // added this on 9/24/21
        {
            result = -1.0;
        }
    }


    return result;
    
    //{
    //if (hours == 12 && mins == 0 && ap == 'a' && type == "in")
    //{
    //    result = 0.00;
    //}
    //else if (hours == 12 && mins == 0 && ap == 'a' && type == "out")
    //{
    //    result == 24.00;
    //}
    //else if (hours == 12 && ap == 'a')
    //{
    //    result = (static_cast<double>(mins) / 60.0);
    //}
    //else if (hours == 12 && ap == 'p')
    //{
    //    result = 12.0 + (static_cast<double>(mins) / 60.0);
    //}
    //
    //else if (ap == 'a')
    //{
    //    result = static_cast<double>(hours) + (static_cast<double>(mins) / 60.0);
    //}
    //else if (ap == 'p')
    //{
    //    result = static_cast<double>(hours) + 12.0 + (static_cast<double>(mins) / 60.0);
    //}
    //else
    //{
    //    std::cout << "ERROR!!! ERROR OCCURED IN `double Time::convert() const` !!!" << std::endl;
    //    result = -1.00;
    //}
    //
    //
    //if (result >= 0.0 && result <= 24.0)
    //    return result;
    //else
    //{
    //    std::cout << "Error occured while converting time to 24 hour format!!!" << std::endl;
    //    return -2.00;
    //}
    //
    //}
}




void Time::sett_time()
{
    std::string data;

    std::cout << "enter the time : ";
    getline(std::cin, data);
    std::stringstream strstm;
    strstm << data;
    std::cout << "Now extracting data..." << std::endl;
    strstm.clear();
    strstm.seekg(0L, std::ios::beg);
    strstm >> hours >> mins >> ap;
    std::cout << "Time is : " << hours << " : " << mins << " " << ap<<std::endl;

    std::cout << "24 hour format of time is : " << convert("in") << std::endl;;


}