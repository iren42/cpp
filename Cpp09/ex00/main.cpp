#include "BitcoinExchange.hpp"

/* a valid value must either be float or positive integer, between 0 and 1 000 */
bool	parse_value(const std::string& s)
{
	double	res;

	res = atof(s.c_str());
	if (res < 0)
	{
		print(ERR_NOT_POS);
		return (false);
	}
	if (res > 1000)
	{
		print(ERR_TOO_BIG);
		return (false);
	}
	return (true);
}

/* function expects the string in format yyyy-mm-dd */
bool	parse_date(const std::string& s, int& d, int& m, int& y){
	std::istringstream is(s);
	char delimiter;

	if (is >> y >> delimiter >> m >> delimiter >> d)
	{
		// initialize
		struct tm local = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		local.tm_mday = d;
		local.tm_mon = m - 1;
		local.tm_year = y - 1900;
		local.tm_isdst = -1;

		// normalize:
		// mktime() interpretes values even if out of their valid ranges
		// e.g. 29/02/2013 would become 01/03/2013
		time_t epoch = mktime(&local);
		const struct tm *norm = localtime(&epoch); // reverse mktime()

		// compare
		return (norm->tm_mday == d    &&
				norm->tm_mon  == m - 1 &&
				norm->tm_year == y - 1900);
	}
	return (false);
}

void	print(const std::string& reason)
{
	std::cout << reason << std::endl;
}

/* checks if the input file has ".txt" as its extension */
bool	parse_filename(const char *s)
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
			if (parse_filename(av[1]) == true)
			{
				BitcoinExchange btc;
				btc.read_db();
				btc.calc(av[1]);
			}
			else
				throw std::runtime_error(ERR_OPEN);
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
