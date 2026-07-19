#include "header.h"

constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;

constexpr hash_t hash_compile_time(const char * str, hash_t last_value = basis)
{
	return *str ? hash_compile_time(str + 1, (*str ^ last_value) * prime) : last_value;
}

bool write_operate(std::ostream& os, const std::map<std::string, std::string> info)
{
	os << "\n";

	for (const auto& item : info)
	{
		if (!(os << item.first << ": " << item.second << "\n"))
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

const std::map<std::string, std::string> ap_operate(const std::vector<std::string>& ap)
{
	std::map<std::string, std::string> m;

	std::string* temp = nullptr;
	bool is_value = false;

	for (const auto& item : ap)
	{
		if (is_value)
		{
			*temp = item;
			is_value = false;
			continue;
		}

		if (item[0] == '-')
		{
			switch (hash_compile_time(item.c_str()))
			{
			case hash_compile_time("-pf"):
				m["platform"] = "\0";
				temp = &m["platform"];
				break;
			
			case hash_compile_time("-phn"):
				m["phonenumber"] = "\0";
				temp = &m["phonenumber"];
				break;

			case hash_compile_time("-em"):
				m["email"] = "\0";
				temp = &m["email"];
				break;

			case hash_compile_time("-pw"):
				m["password"] = "\0";
				temp = &m["password"];
				break;

			case hash_compile_time("-n"):
				m["name"] = "\0";
				temp = &m["name"];
				break;

			case hash_compile_time("-g"):
				m["gender"] = "\0";
				temp = &m["gender"];
				break;

			case hash_compile_time("-a"):
				m["address"] = "\0";
				temp = &m["address"];
				break;
			}

			is_value = true;
		}
	}

	return m;
}

const std::vector<std::string> text_operate(std::ifstream& fin)
{
	std::vector<std::string> vec;

	char temp[300];
	int i = 0;
	std::string item = "";

	while (fin.getline(temp, 300))
	{
		if (temp[0] == '\0')
		{
			vec.push_back(item);
			item = "";
		}

		item += std::string(temp) += '\n';
	}

	if (fin.eof())
	{
		vec.push_back(item);
	}

	return vec;
}

void write_func(const std::vector<std::string>& cmd_vec)
{
	std::ofstream fout;
	if (false)
	{
		//fout.open(path, std::ios::app);
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
		const std::map<std::string, std::string> ap_vec = ap_operate(cmd_vec);

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
		/*std::string string_text;

		fin >> string_text;*/

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
