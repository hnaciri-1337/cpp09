#include <iostream>
#include <map>
#include <fstream>

using namespace std;

class RPN
{
private:
	stack <int>	_data;
	string		nbr;
	string		opr;
	string		expression;
	RPN();
	RPN(RPN const &a);
	RPN & operator = (RPN const &a);
public:
	RPN(string rpnExpression);
	void	calculate();
	void	apply(int t, char op);
	~RPN();
};
