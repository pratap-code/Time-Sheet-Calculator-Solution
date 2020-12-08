#pragma once


#include "Date.h"
#include "Time.h"
#include "Input.h"







//definition of class entry
class Entry
{

    int sno;
    Date d;
    Time intime;
    Time outtime;
    double mo;
    double totaltime;
    double totalpay;
    double netpay;
    std::string notes;

public:

    //constructor
    Entry();

    bool check_entry_validity();

    void reset();

    void construct(Input&);


    void write_text(std::ostream&) const;
    void write_binary(std::ostream&) const;

    void read_text(std::istream&);
    void read_binary(std::istream&);


    void display();

    void set_sno(int);
};




