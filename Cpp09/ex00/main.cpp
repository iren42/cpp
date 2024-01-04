#include "BitcoinExchange.hpp"

void	print(const std::string& reason)
{
	std::cout << reason << std::endl;
}

int main(int ac, char *av[])
{
	if (ac != 2)
		return (1);
	try
	{
		BitcoinExchange btc;
		btc.read_db(DATABASE);
		btc.calc(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
