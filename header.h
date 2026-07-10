#ifndef HEADER_H_
#define HEADER_H_


#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>

const std::string default_path = R"(E:\xdimport\import.txt)";

bool write_operate(std::ostream& os, const std::vector<std::string>& info);

bool read_operate(std::string platform_name, const std::vector<std::string>& info);

void write_func(const std::string& path, std::string ap__);

const std::vector<std::string> ap_operate(std::string& ap);

const std::vector<std::string> text_operate(std::ifstream& fin);

void read_func(const std::string& path, std::string platform_name);

#endif
