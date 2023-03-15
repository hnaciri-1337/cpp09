#include <iostream>
#include <map>
#include <fstream>

using namespace std;

class BitcoinExchange
{
private:
	map <string, float>	_data;
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &a);
	BitcoinExchange & operator = (BitcoinExchange const &a);
public:
	BitcoinExchange(string filename);
	void	execute(string inputfile);
	void	parseLine(string line);
	string	parseDate(string line);
	float	parseNumber(string line);
	~BitcoinExchange();
};
