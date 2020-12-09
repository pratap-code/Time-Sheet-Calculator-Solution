#pragma once

#include<iostream>
#include<string>
#include<sstream>


//definition for class date
class Date
{
    int day;
    int month;
    int year;

public:
    Date(int day = 0, int month = 0, int year = 2020);

    void set_date(int dayVal, int monthVal);

    bool check_date_validity();

    void reset();


    void write_text(std::ostream&) const;
    void write_binary(std::ostream&) const;

    void read_text(std::string&);
    void read_binary(std::string&);



    void construct(int, int);

    void display();

};


