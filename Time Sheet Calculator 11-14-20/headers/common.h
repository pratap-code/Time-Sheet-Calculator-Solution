#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdlib.h>


int get_int();

double get_double();


// need to see if this function is needed
bool ifStrOnly(std::string, const char*); // to  find if a string is made up of specific characters


void smartt_input( std::string, std::string, int xno= -1 );  //this function is self-checking input taking function
				// xno is the expected no of terms in the input and -1 signifies THERE CAN BE ANY NUMBER OF ARGUMENTS