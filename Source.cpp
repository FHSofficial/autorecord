#include <iostream>
#include <fstream>
#include <string>
#include "header.h"

enum Mode { write, read };

int main(int argc, char* argv[])
{
	std::vector<std::string> cmd_vec(3, "\0");	
	// { autorecord ,operate, account and passward, string path }

	for (int i = 1; i < argc; i++)
	{
		cmd_vec[i - 1] = std::string(argv[i]);
	}

	Mode mode = write;

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
		std::cout << "等待完善" << std::endl;
		break;

	default:
		throw std::runtime_error("未知操作");
	}

	return 0;
}
