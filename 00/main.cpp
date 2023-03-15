#include <iostream>
#include "BitcoinExchange.hpp"

using namespace std;

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		cout << "usage : ./btc 'input.txt'" << endl;
		exit (1);
	}
	BitcoinExchange	be ("data.csv");

	be.execute (av[1]);
}
