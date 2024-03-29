#pragma once

#include "common.h"

#include "..\headers\Date.h"
#include "..\headers\Time.h"



//definition of class input
class Input
{
    std::string user_input;
    std::stringstream ss;

    //datamembers to be sent
    int eiday, eimonth, eiyear, eihours, eimins, eoday, eomonth, eoyear, eohours, eomins;
    double emo;
    char eiap, eoap;
    std::string enotes;

public:
    Input();

    void get_input(int&, int&, int&);  // arguments are stored day, time and year
    
    void process_data();

    void get_user_input();
    
 
    //void set_intime();
    //void set_outtime();
  
    void set_other();

    

    // void auto_set_date(int&, int&, int&);

   

    

    
    void reset();

    //getter functions

    
    

    int getiday();
    int getimonth();
    int getiyear();

    int getinhours();
    int getinmins();

    int getoday();
    int getomonth();
    int getoyear();

    int getouthours();
    int getoutmins();

    double getmo();

    char getinap();
    char getoutap();

    std::string getnotes();


    void auto_set_DateTime(int&, int&, int&, const char*);
    void set_time(const char*);

};