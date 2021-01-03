#include "..\headers\Input.h"






Input::Input() : user_input{ "Nothing Entered" }, eiday{ 0 }, eimonth{ 0 }, eiyear{0},
eihours{ 0 }, eimins{ 0 }, eoday{ 0 }, eomonth{ 0 }, eoyear{ 0 }, eohours{ 0 }, eomins{ 0 }, emo{ 0.0 }, eiap{ 'n' }, eoap{ 'n' }, enotes{ "-----" }
{

}


void Input::get_input(int &stored_day, int &stored_month, int &stored_year ) // to store in ss
{
    std::cout << "Enter IN DAY :" << std::endl;
    auto_set_date(stored_day, stored_month, stored_year); //INDAY
    ss << " ";
    set_intime();
    ss << " ";
    
    std::cout << std::endl << std::endl;

    std::cout << "Enter OUT DAY :" << std::endl;
    auto_set_date(stored_day, stored_month, stored_year);
    ss << " ";
    set_outtime();
    ss << " ";
    
    std::cout << std::endl << std::endl;

    set_other();
}


void Input::process_data()
{
    ss.clear();
    ss.seekg(0L, std::ios::beg);
    ss >> eiday>> eimonth >> eiyear >> eihours >> eimins >> eiap 
        >> eoday >> eomonth>> eoyear >> eohours >> eomins >> eoap >> emo >> enotes;
}


void Input::reset()
{
    user_input.clear();

    eiday = eimonth = eiyear = eoday = eomonth = eoyear = eihours = eimins = eohours = eomins = 0;
    emo = 0.0;
    eiap = eoap = 'n';
    enotes = "-----";
    ss.str("");
    ss.clear();
    ss.seekp(0L, std::ios::beg);
}



//definition of getters


int Input::getoday()
{
    return eoday;
}

int Input::getomonth()
{
    return eomonth;
}

int Input::getoyear()
{
    return eoyear;
}

int Input::getiday()
{
    return eiday;
}


int Input::getimonth()
{
    return eimonth;
}

int Input::getiyear()
{
    return eiyear;
}

int Input::getinhours()
{
    return eihours;
}

int Input::getinmins()
{
    return eimins;
}

int Input::getouthours()
{
    return eohours;
}

int Input::getoutmins()
{
    return eomins;
}

double Input::getmo()
{
    return emo;
}

char Input::getinap()
{
    return eiap;
}

char Input::getoutap()
{
    return eoap;
}

std::string Input::getnotes()
{
    return enotes;
}


void Input::get_user_input()
{
    getline(std::cin, user_input);
    ss << user_input;   
    user_input.clear();
}






void Input::set_intime()
{
    std::cout << "Enter IN TIME, FORMAT ( HOURS - MINS - AM/PM ) : ";
    get_user_input();
}


void Input::set_outtime()
{
    std::cout << "Enter OUT TIME, FORMAT ( HOURS - MINS - AM/PM ) : ";
    get_user_input();
}

void Input::set_other()
{
    std::cout << "Do you want to add money owed and notes ( optional, enter n for 0 and no notes ) : ";

    getline(std::cin, user_input);
    if (user_input == "n")
    {
        ss << 0.0 << " " << "-----";
    }
    else
    {
        std::string words;
        std::stringstream tmp;
        int count{ 0 };
        
        tmp << user_input;

        while (tmp >> words)
            ++count;

        if (count == 1)
            ss << user_input << " " << "-----";
        else if (count == 2)
            ss << user_input;
        else
            std::cout << "ERROR OCCURED AT 'void Input::set_other() in Input.cpp' !!!" << std::endl;
    }

}




void Input::auto_set_date(int &day, int &month, int &year)  // check for 0 value of temp
{
    std::string choice;
    
    
    std::cout << "Do you want to use this AUTO DATE, (y for yes, l for day before, e for manually enter ) ** " << day << " / " << month <<" / "<< year << " **   : ";
    getline(std::cin, choice);
    if (choice == "y")
    {
        ss << day << " " << month <<" "<<year; 
       
    }
    else if (choice == "l")
    {
        day = day - 1;
        ss << day << " " << month <<" "<<year;
        
    }
    else if (choice == "e")
    {
        std::cout << "Enter the DATE, FORMAT ( DD - MM - YYYY ) : ";
        getline(std::cin, user_input);
        std::stringstream tmp;
        int tempday{ 0 }, tempmonth{ 0 }, tempyear{ 0 };
        tmp << user_input;
        ss << user_input;
        tmp >> tempday >> tempmonth >> tempyear;
        day = tempday;
        month = tempmonth;
        year = tempyear;
        user_input.clear();
    }
    else
        std::cout << "Invalid choice!!!" << std::endl;

 

}




void Input::get_mod_input()
{
    std::cout << "Please enter the entry FORMAT( [IN]->DD MM YYYY | [IN]->HH MM AP | [O]->DD MM YYYY | [O]->HH MM AP | MO | NOTES ) :" << std::endl;
    getline(std::cin, user_input);
    std::stringstream temp{ user_input };

    ss.str("");
    ss.clear();
    ss.seekp(0L, std::ios::beg);

    ss << user_input;

    int count{};
    std::string word;

    while (temp >> word)
        count++;

    if (count == 12)
        ss << " " << 0.00 << " " << "-----";
    else if (count == 13)
        ss << " " << "-----";
    else if (count == 10)
    {
        char c{ '0' };
    }
    else
        std::cout << "Input ERROR!!!" << std::endl;

    user_input.clear();

}