#pragma once

#include<fstream>
#include<iostream>
#include<string>
#include<vector>

#include "..\headers\Entry.h"

std::string load_file_2();


void read_time_sheet();

// void compare_records(Entry&, Entry&);


std::string tokenize(std::string const&);

void read_records(std::ifstream&, Entry&, std::vector<Entry>&, const char*);

void display_records(std::vector<Entry>& records, const char*);