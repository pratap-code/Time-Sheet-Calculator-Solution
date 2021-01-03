#pragma once

#include "common.h"

#include "..\headers\Entry.h"

std::string load_file_2();


void read_time_sheet();

// void compare_records(Entry&, Entry&);


std::string tokenize(std::string const&);

void read_records(std::ifstream&, Entry&, std::vector<Entry>&, const char*);

void display_records(std::vector<Entry>& records, const char*);


bool check_records(std::vector<Entry>&, std::vector<Entry>&);