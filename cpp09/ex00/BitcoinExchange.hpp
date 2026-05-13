
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <map>

class BitcoinExchange
{
private:
	std::map< std::string, double > _data;
	void ParseDB(void);
	void ReadInputFile(const std::string &inputFile);
	void GetPrice(const std::string &date);

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	BitcoinExchange(const std::string &inputFile);
};

#endif

// one line　→　parser
// db  →　map　→　key: date, value: price
// lower_bound　→　key: date, value: price
