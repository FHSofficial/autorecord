#ifndef HEADER_H_
#define HEADER_H_


#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>
#include <map>

typedef std::uint64_t hash_t;

constexpr hash_t hash_compile_time(const char *, hash_t);

const std::string default_path = R"(E:\xdimport\import.txt)";

bool write_operate(std::ostream& os, const std::map<std::string, std::string> info);

bool read_operate(std::string platform_name, const std::vector<std::string>& info);

void write_func(const std::vector<std::string>& cmd_vec);

const std::map<std::string, std::string> ap_operate(const std::vector<std::string>& ap);

const std::vector<std::string> text_operate(std::ifstream& fin);

void read_func(const std::string& path, std::string platform_name);

#endif
