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

    void display() const;

    int get_day() const;

    int get_month() const;

    int get_year() const;

    friend bool operator==(const Date&, const Date&);

    friend int operator-(const Date&, const Date&);  // check this function's logic maybe it's not right

};


