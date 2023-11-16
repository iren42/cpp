#include "BitcoinExchange.hpp"

/* checks if the input file has ".txt" as its extension */
bool	parseFilename(const char *s)
{
	std::string	filename = s;
	if (filename.find_first_of('.') == filename.find_last_of('.'))
	{
		if (filename.find(".txt") != filename.npos)
		{
			return (true);
		}
	}
	return (false);
}

int main(int ac, char *av[])
{
	try
	{
		if (ac != 2)
			throw std::runtime_error(ERR_OPEN);
		else
		{
			if (parseFilename(av[1]) == true)
			{
				BitcoinExchange *btc = new BitcoinExchange();
				btc->calc(av[1]);
				delete btc;
			}
			else
				throw std::runtime_error(ERR_OPEN);
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
