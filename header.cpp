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

bool read_operate(std::string platform_name, const std::vector<std::string>& info)
{
	for (const auto& it : info)
	{
		if (it.find(platform_name) != std::string::npos)
		{
			std::cout << it;
			return true;
		}
	}

	return false;
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

const std::vector<std::string> text_operate(std::ifstream& fin)
{
	std::vector<std::string> vec;

	char temp[300];
	int i = 0;
	std::string item = "";

	while (fin.getline(temp, 300))
	{
		item += (std::string)temp += '\n';

		if (temp[0] == '\0')
		{
			vec.push_back(item);
			item = "";
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


void read_func(const std::string& path, std::string platform_name)
{
	std::ifstream fin;
	if (path != "\0")
	{
		fin.open(path, std::ios::in);
	}
	else
	{
		std::string string_text;

		fin >> string_text;

		fin.open(default_path);
	}

	if (!fin.is_open())
	{
		std::cout << "文件无法打开" << std::endl;
		exit(1);
	}

	try
	{
		const std::vector<std::string> vec = text_operate(fin);
		
		if (!read_operate(platform_name, vec))
		{
			std::cout << "未找到此平台" << std::endl;
		}

		fin.close();
	}
	catch (const std::exception& e)
	{
		fin.close();
		std::cout << e.what() << std::endl;
	}
}
