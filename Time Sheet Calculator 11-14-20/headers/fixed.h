#pragma once

#include<cmath>


//declaration of fixed-point values
class fixed
{
	int value;
	int n;

public:
	
	fixed();
	
	double get() const;
	
	void set();
	void set(std::string&);
	
	
	std::string parse(std::string&) const;

	void display() const;

	void create(double);

};
