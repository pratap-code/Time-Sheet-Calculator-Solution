#pragma once

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>


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


    void write_text(std::ofstream&) const;
    void write_binary(std::ofstream&) const;

    void read_binary(std::ifstream&);



    void construct(int, int);

    void display();

    int get_day();

    int get_month();

    int get_year();

    friend bool operator==(const Date&, const Date&);

};


