#pragma once

#include "common.h"

#include "Date.h"
#include "Time.h"


class DateTime
{
private:
	Date date;
	Time time;

public:
	DateTime();

	void reset();

	bool check_DateTime_validity();


	void write_text(std::ofstream&) const;
	void write_binary(std::ofstream&) const;

	void read_binary(std::ifstream&);

	void construct(int, int, int, int, int, char);

	void display() const;



	int get_Date(const char*) const;

	friend bool operator==(const DateTime&, const DateTime&);

	int get_Time_num(const char*) const;

	char get_Time_ap() const;

	double get_hh(const char*) const;

};