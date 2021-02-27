#pragma once

#include "common.h"

#include "..\headers\DateTime.h"
#include "..\headers\Input.h"







//definition of class entry
class Entry
{

    int sno;
    DateTime in;
    DateTime out;

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


    void write_text(std::ofstream&) const;
    void write_binary(std::ofstream&) const;

    void read_text(std::string);
    void read_binary(std::ifstream&);


    void display();

    void set_sno(int);

    int get_sno();

    void mod_sno(const char*);

    int get_Date(const char*);

    friend bool operator==(const Entry&, const Entry&);

    void calculate();

    double hours_elapsed() const;


    
};




