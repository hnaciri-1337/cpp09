#include <iostream>
#include "RPN.hpp"

using namespace std;

int	main(int ac, char **av)
{
	RPN	a (av[1]);
	if (ac != 2)
	{
		cout << "usage : ./RPN 'RPN EXPRESSION TO CALCULATE'" << endl;
		exit (1);
	}
	a.calculate();
}
