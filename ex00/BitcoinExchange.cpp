#include "BitcoinExchange.hpp"

const char *WHITESPACE = " \t\n\r";

static std::string &ltrim(std::string &s)
{
	s.erase(0, s.find_first_not_of(WHITESPACE));
	return s;
}

static std::string &rtrim(std::string &s)
{
	s.erase(s.find_last_not_of(WHITESPACE) + 1);
	return s;
}

static std::string &trim(std::string &s)
{
	return ltrim(rtrim(s));
}

Btc::Btc()
{
	int i = 0;
	this->readFlag = 1;
	std::ifstream file("./data.csv");
	if (!file.is_open())
	{
		this->readFlag = 0;
		return;
	}
	std::string line;
	while (std::getline(file, line))
	{
		if (i == 0)
		{
			i = 1;
			continue;
		}
		size_t pos = line.find(',');
		if (pos == std::string::npos)
		{
			std::cerr << "Error : Invalid Paramter" << std::endl;
			continue;
		}
		std::string date = line.substr(0, pos);
		float value;
		try
		{
			value = static_cast<float>(strtod(line.substr(pos + 1).c_str(), NULL));
		}
		catch (std::exception &a)
		{
			(void)a;
			std::cerr << "Error: could not parse value" << std::endl;
			continue;
		}
		this->setData(date, value);
	}
	file.close();
}

Btc::~Btc()
{
}

Btc &Btc::operator=(Btc const &copy)
{
	this->data = copy.data;
	return (*this);
}

Btc::Btc(Btc const &src)
{
	*this = src;
}

void Btc::setData(std::string date, float value)
{
	this->data.insert(std::make_pair(date, value));
}

std::map<std::string, float> Btc::getData()
{
	return (this->data);
}

std::vector<std::string> Btc::splitString(std::string str, char delimiter)
{
	std::vector<std::string> substrings;
	std::string substring = "";
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != delimiter)
		{
			substring += str[i];
		}
		else
		{
			substrings.push_back(substring);
			while (str[i] == delimiter)
				i++;
			i--;
			substring = "";
		}
	}
	substrings.push_back(substring);
	return substrings;
}

void Btc::readInput(std::string inputPath)
{
	int i = 0;
	std::ifstream file2(inputPath.c_str());
	if (!file2.is_open())
	{
		this->readFlag = -1;
		return;
	}
	std::string line;
	std::vector<std::string> vectorLine;
	while (std::getline(file2, line))
	{
		if (i == 0)
		{
			i = 1;
			continue;
		}
		vectorLine = this->splitString(line, '|');
		if (vectorLine[1].length() == 0 || vectorLine.size() < 2)
		{
			std::cout << "Error: bad input => " << vectorLine[0] << std::endl;
			continue;
		}
		std::map<std::string, float>::iterator it = this->data.upper_bound(trim(vectorLine[0]));
		if (it != this->data.end())
		{
			std::pair<std::string, float> p = *(--it);
			try
			{
				if (strtod(vectorLine[1].c_str(), NULL) > 1000)
				{
					std::cout << "Error: too large a number." << std::endl;
				}
				else if (strtod(vectorLine[1].c_str(), NULL) < 0)
				{
					std::cout << "Error: not a positive number." << std::endl;
				}
				else
					std::cout << vectorLine[0] << " => " << vectorLine[1] << " = " << strtod(vectorLine[1].c_str(), NULL) * p.second << std::endl;
			}
			catch (const std::exception &e)
			{
				(void)e;
				std::cout << "Error : Input Not A Number" << std::endl;
				continue;
			}
		}
	}
	file2.close();
}
