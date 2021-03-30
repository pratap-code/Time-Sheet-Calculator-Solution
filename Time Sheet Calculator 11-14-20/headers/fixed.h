#pragma once


//declaration of fixed-point values
class fixed
{
	int value;
	int n;

public:
	
	fixed();
	
	double get() const;
	void set();
	
	std::string parse(std::string&) const;

	void display() const;

};
