#pragma once

#include <string>
#include<sstream>
#include "Date.h"
#include "Time.h"



//definition of class input
class Input
{
    std::string user_input;
    std::stringstream ss;

    //datamembers to be sent
    int eday, emonth, eihours, eimins, eohours, eomins;
    double emo;
    char eiap, eoap;
    std::string enotes;

public:
    Input();

    void get_input(int&,int&);
    
    void process_data();

    void get_user_input();
    
 
    void set_intime();
    void set_outtime();
  
    void set_other();

    

    void auto_set_date(int&,int&);

   

    

    
    void reset();

    //getter functions

    int getday();
    int getmonth();
    int getinhours();
    int getinmins();
    int getouthours();
    int getoutmins();
    double getmo();
    char getinap();
    char getoutap();
    std::string getnotes();
};