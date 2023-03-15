#include "BitcoinExchange.hpp"



BitcoinExchange::BitcoinExchange(string filename)
{
	ifstream	file;

	file.open(filename);
	if (file.fail())
	{
		cout << "FAILED TO GET DATABASE\n";
		exit (1);
	}
	while (!file.eof())
	{
		string	line;
		
		getline(file, line);
		try
		{
			_data.insert (make_pair(line.substr(0, 10), stof(line.substr(11))));
		}
		catch(const std::exception& e) {}
	}
}

string	BitcoinExchange::parseDate(string date)
{
	string	valid = "0123456789-";
	int	c = count(date.begin(), date.end(), '-');
	if (c != 2 || date[date.size() - 1] != ' ')
	{
		cout << "Error: bad date => " << date << endl;
		return ("");
	}
	date.erase (--date.end());
	for (int i = 0; i < date.size(); i++)
		if (valid.find(date[i]) == string::npos)
		{
			cout << "Error: bad date => " << date << endl;
			return ("");
		}
	return (date);
}

float	BitcoinExchange::parseNumber(string number)
{
	int	c = count(number.begin(), number.end(), '.');
	string	valid = "0123456789.";
	if (number[0] != ' ' || c > 1)
	{
		cout << "Error: bad value => " << number << endl;
		return (-1.000);
	}
	number.erase (number.begin());
	if (number[0] == '-')
	{
		cout << "Error: not a positive number => " << number << endl;
		return (-1.000);
	}
	for (int i = 0; i < number.size(); i++)
		if (valid.find(number[i]) == string::npos)
		{
			cout << "Error: bad value => " << number << endl;
			return (-1.000);
		}
	float	value = stof(number);
	if (value > 1000.000)
	{
		cout << "Error: too large a number => " << number << endl;
		return (-1.000);
	}
	return (value);
}

void	BitcoinExchange::parseLine(string line)
{
	int	c = count(line.begin(), line.end(), '|');
	if (c != 1)
	{
		cout << "Error: bad input => " << line << endl;
		return ;
	}
	c = line.find('|');
	string	date = parseDate(line.substr(0, c));
	float	number = parseNumber(line.substr(c + 1));
	if (date.empty() || number == -1.000)
		return ;
	cout << date << " => " << number << " = " << number * (--_data.upper_bound(date))->second << endl;
}

void	BitcoinExchange::execute(string inputfile)
{
	ifstream	file;

	file.open(inputfile);
	if (file.fail())
	{
		cout << "FAILED TO OPEN :" << inputfile << endl;
		exit (1);
	}
	while (!file.eof())
	{
		string	line;
		getline(file, line);
		parseLine(line);
	}
}

BitcoinExchange::~BitcoinExchange() {}
