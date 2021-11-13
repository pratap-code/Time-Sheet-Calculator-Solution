#pragma once

#include "common.h"

// this defines a class to take input in a smart way that is self checking

// need to add type check for variables  .... 

// how to ensure the order of entering is correct


class smart_input
{
	private:
		std::string inp;     // this is the actual input entered by the user
		std::string xinp;    // this is the expected input
		int xno;			 // this is expected no. of terms, -1 signifies there can be an arbitrary no. of  terms

	public:
		smart_input();

		void get_input( std::string, std::string,  int&);  // to get inp and xinp and xno

		void parse_xinp();  // to parse xinp

		void parse();

		void split(std::string&) const; // to split words depending on what kind of word it is

		bool check_num(std::string&, char&) const;


};
