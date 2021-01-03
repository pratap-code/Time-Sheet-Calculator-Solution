#pragma once


#include "common.h"
#include "..\headers\Entry.h"


std::string load_file();

void enter_data();

void open_file(std::ifstream& file_op, std::string& filename_op, const char*);

void open_file(std::ofstream& file_op, std::string& filename_op, const char*);

void create_vector(Input&, Entry&, std::vector<Entry>& records);

void write_to_file(std::ofstream&, std::vector<Entry>& records, const char*);

void display_vector(std::vector<Entry>& records);