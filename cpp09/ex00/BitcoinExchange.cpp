#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_data = other._data;
	}
	return *this;
}
// 4. mktime によって値が書き換えられていたら、元の日付が異常だった証拠
// 例: 5月32日を入力すると、mktimeは自動的に6月1日に変換してしまう

//validate date format (YYYY-MM-DD)
bool isValidDate(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	int year, month, day;
	int parsed = std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
	if (parsed != 3)
		return false;
	std::tm t = {};
	t.tm_year = year - 1900;
	t.tm_mon = month - 1;
	t.tm_mday = day;
	int raw_mday = t.tm_mday;
	int raw_mon = t.tm_mon;
	int raw_year = t.tm_year;
	std::mktime(&t);
	if (t.tm_mday != raw_mday || t.tm_mon != raw_mon || t.tm_year != raw_year)
		return false;
	return true;
}

//validate value format
bool isValidValue(const std::string &value)
{
	std::stringstream ss(value);
	double val;
	ss >> val;
	if (ss.fail() || !ss.eof())
	{
		return false;
	}
	return true;
}

// Trim leading and trailing spaces
static std::string trimSpaces(const std::string &str)
{
	size_t start = str.find_first_not_of(" \t\r\n");
	size_t end = str.find_last_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";
	return str.substr(start, end - start + 1);
}

// inputfile Syntax:
// • Each line in this file must use the following format : "date | value".
// • A valid date will always be in the following format : Year - Month - Day.
// • A valid value must be either a double or a positive integer, between 0 and 1000.

bool validInputLine(const std::string &line)  // one line　→　parser
{
	if ((line.find('|') == std::string::npos || !isValidDate(trimSpaces(line.substr(0, line.find('|')))) || !isValidValue(trimSpaces(line.substr(line.find('|') + 1)))))
	{
		std::string error = "bad input => " + line;
		throw std::runtime_error(error);
		return false;
	}
	return true;
}
bool isValidDB(const std::string &line)
{
	if (!isValidDate(trimSpaces(line.substr(0, line.find(',')))) || !isValidValue(trimSpaces(line.substr(line.find(',') + 1))) || !isValidValue(trimSpaces(line.substr(line.find(',') + 1))))
	{
		std::string error = "Invalid line in data.csv: " + line;
		throw std::runtime_error(error);
		return false;
	}
	return true;
}
void BitcoinExchange::ParseDB(void)	 // one line　→　parser
{
	std::string line;
	std::ifstream db("data.csv");
	if (!db.is_open())
		throw std::runtime_error("Failed to open data.csv");
	std::getline(db, line);	 // Skip header line
	while (std::getline(db, line))
	{
		// Parse each line and insert into _data map
		if (isValidDB(line))
		{
			std::string date = line.substr(0, line.find(','));
			std::stringstream priceStream(line.substr(line.find(',') + 1));
			double price;
			priceStream >> price;
			if (this->_data.find(date) != this->_data.end())
			{
				std::string error = "Duplicate date in data.csv: " + date;
				throw std::runtime_error(error);
			}
			if (price < 0)
			{
				std::string error = "Negative price in data.csv: " + line;
				throw std::runtime_error(error);
			}
			this->_data[date] = price;
		}
		else
		{
			std::string error = "Invalid line in data.csv: " + line;
			throw std::runtime_error(error);
		}
	}
}

void BitcoinExchange::GetPrice(const std::string &line)	 // one line　→　parser
{
	std::string date = trimSpaces(line.substr(0, line.find('|')));
	std::map< std::string, double >::iterator it = this->_data.lower_bound(date);
	//debug
	std::cout << "Looking for date: " << date << " | Get it: " << it->first << std::endl;
	if (it->first != date)
	{
		if (it != this->_data.begin())	// lower_boundが見つからない場合は、前のエントリーを使用
			--it;	
		else
		{
			std::string error = "No data available for date: " + date;
			throw std::runtime_error(error);
		}
	}
	double price = it->second;
	std::stringstream valueStream(trimSpaces(line.substr(line.find('|') + 1)));
	double value;
	valueStream >> value;
	if (value < 0 || value > 1000)
	{
		std::string error = value < 0 ? "not a positive number." : "too large a number.";
		throw std::runtime_error(error);
	}
	// debug
	std::cout << "Price for date " << it->first << " is " << price << std::endl;
	std::cout << date << " => " << value << " = " << value * price << std::endl;
}

void BitcoinExchange::ReadInputFile(const std::string &inputFile)  // one line　→　parser
{
	std::string line;
	std::ifstream input(inputFile.c_str());
	if (!input.is_open())
		throw std::runtime_error("Failed to open input file: " + inputFile);
	std::getline(input, line);	// Skip header line
	while (std::getline(input, line))
	{
		try
		{
			if (validInputLine(line))
				GetPrice(line);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
}

BitcoinExchange::BitcoinExchange(const std::string &inputFile)
{
	ParseDB();
	std::cout << "Parsed data.csv successfully." << std::endl;
	ReadInputFile(inputFile);
}
