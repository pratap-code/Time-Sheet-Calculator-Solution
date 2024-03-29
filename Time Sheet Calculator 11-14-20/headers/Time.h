#pragma once

#include "common.h"



//definition of time class
class Time
{
    int hours;
    int mins;
    char ap;

public:
    Time(int hours = 0, int mins = 0, char ap = 'n');
    bool check_time_validity();
    void set_time(int hoursVal, int minsVal, char apVal);  // this is not used anywhere --> get rid of it
    void reset();


    void write_text(std::ofstream&) const;
    void write_binary(std::ofstream&) const;

    void read_binary(std::ifstream&);

    void construct(int, int, char);

    void display() const;

    friend bool operator==(const Time&, const Time&);

    //getters

    int get_hours() const;
    int get_mins() const;
    char get_ap() const;

    double convert(const char *) const;  // to convert time to 24 hr format

    void sett_time();

    


};

