#include <iostream>
#include <fstream>
#include <string>
#include "header.h"

enum Mode { write, read, none };

int main(int argc, char* argv[])
{
	std::vector<std::string> cmd_vec(3, "\0");	
	// { autorecord ,operate, account and passward, string path }
	// { autorecord, operate, platform name, string path}
	//                  0         1                 2

	for (int i = 1; i < argc; i++)
	{
		cmd_vec[i - 1] = std::string(argv[i]);
	}

	Mode mode = none;

	if (cmd_vec[0] == "write")
		mode = write;
	else if (cmd_vec[0] == "read")
		mode = read;

	switch (mode)
	{
	case write:
		write_func(cmd_vec[2], cmd_vec[1]);
		break;

	case read:
		read_func(cmd_vec[2], cmd_vec[1]);
		break;

	default:
		std::cout << "autorecord 没有此参数" << std::endl;
	}

	return 0;
}