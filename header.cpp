#include "header.h"

bool write_operate(std::ostream& os, const std::vector<std::string>& info)
{
	os << "\n";

	for (std::vector<std::string>::const_iterator it = info.begin(); it != info.end(); it++)
	{
		if (!(os << *it << "\n"))
		{
			return false;
		}
	}

	return true;
}

const std::vector<std::string> ap_operate(std::string& ap)
{
	std::vector<std::string> vec;

	std::string::iterator temp = ap.begin();

	for (std::string::iterator it = ap.begin(); it != ap.end(); it++)
	{
		if (*it == ',')
		{
			vec.push_back(std::string(temp, it));
			temp = it + 1;
		}
		if (it + 1 == ap.end())
		{
			vec.push_back(std::string(temp, it + 1));
		}
	}

	return vec;
}

void write_func(const std::string& path, std::string ap__)
{
	std::ofstream fout;
	if (path != "\0")
	{
		fout.open(path, std::ios::app);
	}
	else
	{
		fout.open(default_path, std::ios::app);
	}

	if (!fout.is_open())
	{
		std::cout << "目标文件无法打开" << std::endl;
		exit(1);
	}

	try
	{
		const std::vector<std::string> ap_vec = ap_operate(ap__);

		if (!write_operate(std::cout, ap_vec))
		{
			std::cout.clear();
			std::cout << "写入cmd失败" << std::endl;
		}
		if (!write_operate(fout, ap_vec))
		{
			std::cout << "写入文件失败" << std::endl;
		}

		fout.close();
	}
	catch (const std::exception& e)
	{
		fout.close();
		std::cout << e.what() << std::endl;
	}
}