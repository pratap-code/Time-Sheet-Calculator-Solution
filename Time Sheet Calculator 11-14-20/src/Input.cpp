#include "..\headers\Input.h"






Input::Input() : user_input{ "Nothing Entered" }, eiday{ 0 }, eimonth{ 0 }, eiyear{0},
eihours{ 0 }, eimins{ 0 }, eoday{ 0 }, eomonth{ 0 }, eoyear{ 0 }, eohours{ 0 }, eomins{ 0 }, emo{ 0.0 }, eiap{ 'n' }, eoap{ 'n' }, enotes{ "-----" }
{

}


void Input::get_input(int &stored_day, int &stored_month, int &stored_year ) // to store in ss
{
    //std::cout << "Enter IN DAY :" << std::endl;
    //auto_set_date(stored_day, stored_month, stored_year); //INDAY
    //ss << " ";
    //set_intime();
    //ss << " ";
    //
    //std::cout << std::endl << std::endl;
    //
    //std::cout << "Enter OUT DAY :" << std::endl;
    //auto_set_date(stored_day, stored_month, stored_year);
    //ss << " ";
    //set_outtime();
    //ss << " ";

    auto_set_DateTime(stored_day, stored_month, stored_year, "IN");
    ss << " ";
    auto_set_DateTime(stored_day, stored_month, stored_year, "OUT");
    ss << " ";
        
    std::cout << std::endl;

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
    ss.seekp(0L, std::ios::beg);  // to reset both read and write pointers in stream
    ss.seekg(0L, std::ios::beg);
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




void Input::set_time(const char* time_type)
{
    std::cout << "Enter "<<time_type<<" TIME, FORMAT ( HOURS - MINS - AM/PM ) : ";
    get_user_input();
}






//void Input::set_intime()
//{
//    std::cout << "Enter IN TIME, FORMAT ( HOURS - MINS - AM/PM ) : ";
//    get_user_input();
//}
//
//
//void Input::set_outtime()
//{
//    std::cout << "Enter OUT TIME, FORMAT ( HOURS - MINS - AM/PM ) : ";
//    get_user_input();
//}

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



//void Input::auto_set_date(int &day, int &month, int &year)  // check for 0 value of temp
//{
//    std::string choice;
//    
//    
//    std::cout << "Do you want to use this AUTO DATE, (y for yes, l for day before, e for manually enter ) ** " << day << " / " << month <<" / "<< year << " **   : ";
//    getline(std::cin, choice);
//    if (choice == "y")
//    {
//        ss << day << " " << month <<" "<<year; 
//       
//    }
//    else if (choice == "l")
//    {
//        day = day - 1;
//        ss << day << " " << month <<" "<<year;
//        
//    }
//    else if (choice == "e")
//    {
//        std::cout << "Enter the DATE, FORMAT ( DD - MM - YYYY ) : ";
//        getline(std::cin, user_input);
//        std::stringstream tmp;
//        int tempday{ 0 }, tempmonth{ 0 }, tempyear{ 0 };
//        tmp << user_input;
//        ss << user_input;
//        tmp >> tempday >> tempmonth >> tempyear;
//        day = tempday;
//        month = tempmonth;
//        year = tempyear;
//        user_input.clear();
//    }
//    else
//        std::cout << "Invalid choice!!!" << std::endl;
//
// 
//
//}







//void Input::auto_set_DateTime(int &stored_day, int &stored_month, int &stored_year, const char* time_type)  // need to polish this
//{
//    std::cout << "AUTO DATE : " << stored_day << "/" << stored_month << "/" << stored_year << std::endl;
//    std::cout << "Enter " << time_type << " time or 'l and time to use a day before with time' or just enter " << time_type
//        << " Date :" << std::endl;    // choice is either just to enter time and pick up date from stored data
//                                      // or to use last without typing
//                                      // note idea is to use single date for a single entry
//                                      // because auto date increases day by one each time  
//                                      // n means next day and l means last day.   
//
//    getline(std::cin, user_input);
//
//    std::stringstream tmp{ user_input };
//    std::vector<std::string>words;
//    std::string word;
//    int count{};
//
//    if (tmp)
//    {
//        while (tmp >> word)
//        {
//            words.push_back(word);
//            ++count;
//        }
//        
//        if (count == 3)
//        {
//            if (words[2] == "a" || words[2] == "p")
//            {
//                ss << stored_day << " " << stored_month << " " << stored_year;
//                ss << " ";
//                ss << words[0] << " " << words[1] << " " << words[2];
//            }
//            else
//            {
//                // to store entered date into stored date
//                tmp.clear();
//                tmp.seekg(0L, std::ios::beg);
//                tmp >> stored_day >> stored_month >> stored_year;
//
//                std::cout << "AUTO DATE : " << stored_day << "/" << stored_month << "/" << stored_year << std::endl;
//
//                
//                ss << words[0] << " " << words[1] << " " << words[2];
//                ss << " ";
//                std::cout << "Enter " << time_type << " time : ";
//                set_time(time_type);                
//            }
//        }
//        else if (count == 1)  // need to understand this
//        {
//            tmp.clear();
//            tmp.seekg(0L, std::ios::beg);
//            tmp >> stored_day;
//
//            std::cout << "AUTO DATE : " << stored_day << "/" << stored_month << "/" << stored_year << std::endl;
//
//            ss << stored_day << " " << stored_month << " " << stored_year;
//            ss << " ";
//            std::cout << "Enter " << time_type << " time : ";
//            set_time(time_type);
//        }     
//        else if (count == 4)
//        {
//            if (words[0] == "l")
//            {
//                stored_day= stored_day - 1;
//                
//                std::cout << "AUTO DATE : " << stored_day << "/" << stored_month << "/" << stored_year << std::endl;
//
//                ss << stored_day << " " << stored_month << " " << stored_year << " " << words[1] << " " << words[2] << " " << words[3];
//            }
//            else if (words[0] == "n")
//            {
//                stored_day = stored_day + 1;
//
//                std::cout << "AUTO DATE : " << stored_day << "/" << stored_month << "/" << stored_year << std::endl;
//
//
//                ss << stored_day <<" "<< stored_month << " " << stored_year << " " << words[1] << " " << words[2] << " " << words[3];
//            }
//            else
//            {
//                std::cout << "Error occured in 'void Input::auto_set_DateTime()` !!!" << std::endl;
//            }
//        }
//        else
//        {
//            std::cout << "Error occured in 'void Input::auto_set_DateTime()` !!!" << std::endl;
//        }
//    }
//    else
//    {
//        std::cout << "ERROR! stringstream tmp is empty!!!" << std::endl;
//    }
//}



//this is updated function based on count

void Input::auto_set_DateTime(int& stored_day, int& stored_month, int& stored_year, const char* time_type)  // need to polish this
{
    std::cout << "AUTO DATE : " << stored_day << "/" << stored_month << "/" << stored_year << std::endl;
    
    std::cout << "Enter DATE AND TIME with following format::" << std::endl;
    std::cout << "1. used stored date and just enter time" << std::endl
              << "2. l and time to use day before and time" << std::endl
              << "3. n and time to use next day and time" << std::endl
              << "4. day only and time" << std::endl
              << "5. day and month and time" << std::endl
              << "6. day, month, year and time" << std::endl << std::endl;

    getline(std::cin, user_input);

    std::stringstream tmp{ user_input };
    std::vector<std::string>words;
    std::string word;
    int count{};

    if (tmp)
    {
        while (tmp >> word)
        {
            words.push_back(word);
            ++count;
        }

        if (count == 3)
        {
            if (words[2] == "a" || words[2] == "p")
            {
                ss << stored_day << " " << stored_month << " " << stored_year;
                ss << " ";
                ss << words[0] << " " << words[1] << " " << words[2];
            }
            else
            {
                std::cout << "ERROR!! Invalid input entered in Input::user_input in function" << std::endl
                    << "void Input::auto_set_DateTime(int& stored_day, int& stored_month, int& stored_year, const char* time_type) in Input.cpp" << std::endl << std::endl;
            }
        }
        else if (count == 4)
        {
            if (words[0] == "l")
            {
                stored_day = stored_day - 1;

                std::cout << "AUTO DATE : " << stored_day << "/" << stored_month << "/" << stored_year << std::endl;

                ss << stored_day << " " << stored_month << " " << stored_year << " " << words[1] << " " << words[2] << " " << words[3];
            }
            else if (words[0] == "n")
            {
                stored_day = stored_day + 1;

                std::cout << "AUTO DATE : " << stored_day << "/" << stored_month << "/" << stored_year << std::endl;


                ss << stored_day << " " << stored_month << " " << stored_year << " " << words[1] << " " << words[2] << " " << words[3];
            }
            else if ( ifStrOnly(words[0],"0123456789") ) // checking to see if words[0] contains only digits
            {
                std::stringstream tmp;
                tmp << words[0];
                int day{};
                tmp >> day;
                stored_day = day;

                std::cout << "Date entered : " << stored_day << "/" << stored_month << "/" << stored_year << std::endl;
                ss << stored_day << " " << stored_month << " " << stored_year << " " << words[1] << " " << words[2] << " " << words[3];
                ss << " ";  
            }
            else
            {
                std::cout << "Error occured in 'void Input::auto_set_DateTime()` !!!" << std::endl;
            }
        }
        else if (count == 5)
        {
            if (ifStrOnly(words[0], "0123456789") && ifStrOnly(words[1], "0123456789"))
            {
                int num{-99999};  // -99999 is considered initial state of variable, -9999 is state after any use
                std::stringstream tmp;
                tmp << words[0] << " " << words[1];
                tmp.clear();
                tmp.seekg(0L, std::ios::beg);

                tmp >> num; //date
                stored_day = num;
                num = -9999;

                tmp >> num; //month
                stored_month = num;
                num = -9999;

                ss << stored_day << " " << stored_month << " " << stored_year << " " << words[2] << " " << words[3] << " " << words[4];
                ss << " ";
            }
            else
            {
                std::cout << "Error!!! Incorrect input entered in 'void Input::auto_set_DateTime(int&, int&, int&, const char*)' in Input.cpp!!!" << std::endl;
            }
        }
        else if (count == 6)
        {
            if (ifStrOnly(words[0], "0123456789") && ifStrOnly(words[1], "0123456789") && ifStrOnly(words[2], "0123456789"))
            {
                tmp.clear();                    // resetting the tmp stringstream
                tmp.seekg(0L, std::ios::beg);


            }
            else
            {
                std::cout << "Error!!! Incorrect input entered in 'void Input::auto_set_DateTime(int&, int&, int&, const char*)' in Input.cpp!!!" << std::endl;
            }
        }
        else
        {
            std::cout << "Error occured in 'void Input::auto_set_DateTime()` !!!" << std::endl;
        }
    }
    else
    {
        std::cout << "ERROR! stringstream tmp is empty!!!" << std::endl;
    }


}