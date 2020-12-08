#pragma once

#include<vector>
#include<fstream>

#include "..\headers\common.h"
#include "..\headers\Entry.h"


std::string load_file();

void enter_data();

void open_file(std::ifstream& file_op, std::string& filename_op, std::string);

void open_file(std::ofstream& file_op, std::string& filename_op, std::string);

void create_vector(Input&, Entry&, std::vector<Entry>& records);

void write_to_file(std::ostream&, std::vector<Entry>& records, std::string);

void display_vector(std::vector<Entry>& records);