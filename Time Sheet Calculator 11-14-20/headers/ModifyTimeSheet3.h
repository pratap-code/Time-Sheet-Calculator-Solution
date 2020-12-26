#pragma once

#include "..\headers\EnterData1.h"
#include "..\headers\ViewTimeSheet2.h"


void modify();

void modify_records(std::vector<Entry>&,std::vector<Entry>&);


void insert(std::vector<Entry>&, int&, Entry &);

void delete_rec(std::vector<Entry>&, int);

void add_records(std::vector<Entry>&);

void write_modified_data(std::vector<Entry>&, std::string&, std::string&);

