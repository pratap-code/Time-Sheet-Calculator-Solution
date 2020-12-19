#pragma once


#include <iostream>
#include<string>
#include<sstream>
#include<fstream>


//definition of time class
class Time
{
    int hours;
    int mins;
    char ap;

public:
    Time(int hours = 0, int mins = 0, char ap = 'n');
    bool check_time_validity();
    void set_time(int hoursVal, int minsVal, char apVal);
    void reset();


    void write_text(std::ofstream&) const;
    void write_binary(std::ofstream&) const;

    void read_binary(std::ifstream&);

    void construct(int, int, char);

    void display();
};

