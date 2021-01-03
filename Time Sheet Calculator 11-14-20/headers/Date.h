#pragma once

#include "common.h"


//definition for class date
class Date
{
       
    int day;
    int month;
    int year;

public:
    Date(int day = 0, int month = 0, int year = 0);

    

    bool check_date_validity();

    void reset();


    void write_text(std::ofstream&) const;
    void write_binary(std::ofstream&) const;

    void read_binary(std::ifstream&);



    void construct(int, int, int);

    void display();

    int get_day();

    int get_month();

    int get_year();

    friend bool operator==(const Date&, const Date&);

};


