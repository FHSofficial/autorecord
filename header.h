#ifndef HEADER_H_
#define HEADER_H_


#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>

const std::string default_path = R"(E:\xdimport\import2.txt)";

bool write_operate(std::ostream& os, const std::vector<std::string>& info);

void write_func(const std::string& path, std::string ap__);

const std::vector<std::string> ap_operate(std::string& ap);

#endif
