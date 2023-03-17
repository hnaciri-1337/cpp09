#include "RPN.hpp"

RPN::RPN(string rpnExpression) {
	nbr = "0123456789 ";
	opr = "+-*/";
	expression = rpnExpression;
	int	numbers = 0;
	int	operators = 0;
	for (int i = 0; i < rpnExpression.size(); i++)
	{
		if (nbr.find(rpnExpression[i]) == string::npos && opr.find(rpnExpression[i]) == string::npos)
		{
			cout << "Error\ninvalid character: " << rpnExpression[i] << endl;
			exit (1);
		}
	}
	for (char c = '0'; c <= '9'; c++)
		numbers += count (rpnExpression.begin(), rpnExpression.end(), c);
	operators += count (rpnExpression.begin(), rpnExpression.end(), '+');
	operators += count (rpnExpression.begin(), rpnExpression.end(), '-');
	operators += count (rpnExpression.begin(), rpnExpression.end(), '*');
	operators += count (rpnExpression.begin(), rpnExpression.end(), '/');
	if (numbers <= operators)
	{
		cout << "Error\ninvalid RPN expression" << endl;
		exit (1);
	}
}

void	RPN::apply (int t, char op)
{
	if (op == '*')
		_data.top () *= t;
	else if (op == '/')
		_data.top () /= t;
	else if (op == '+')
		_data.top () += t;
	else if (op == '-')
		_data.top () -= t;
}

void	RPN::calculate()
{	
	for (int i = 0; i < expression.size(); i++)
	{
		if (isdigit(expression[i]))
			_data.push (expression[i] - 48);
		else if (opr.find(expression[i]) != string::npos)
		{
			if (_data.size () < 2)
			{
				cout << "Error\nINRUGULAR RPN Expression" << endl;
				exit (1);
			}
			int	t = _data.top ();
			_data.pop ();
			if (t == 0 && expression[i] == '/')
			{
				cout << "Error\nCannot devise by 0" << endl;
				exit (1);
			}
			apply (t, expression[i]);
 		}
	}
	cout << _data.top () << endl;
}

RPN::~RPN() {}
