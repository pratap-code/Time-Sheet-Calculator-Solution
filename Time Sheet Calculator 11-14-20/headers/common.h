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


void smart_input(std::string, int, std::string);  //this function is self-checking input taking function