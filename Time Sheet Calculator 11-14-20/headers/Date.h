#pragma once

#include<iostream>


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

    void read_text(std::istream&);
    void read_binary(std::istream&);



    void construct(int, int);

    void display();

};


