#include "BitcoinExchange.hpp"

//		std::cout << << std::endl;
BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(*this) = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_db = other._db;
	return (*this);
}

bool	BitcoinExchange::is_digit(char c)
{
	if (c < '0' || c > '9')
		return (false);
	return (true);
}

bool	BitcoinExchange::is_number(const std::string& line)
{
	std::string::const_iterator	it = line.begin();
	int	dot;

	dot = 1;
	it++; // move past ' '
	while (it != line.end())
	{
		if ((*it < '0' || *it > '9') && *it != '.')
			return (false);
		if (*it == '.')
			dot--;
		it++;
	}
	if (dot < 0)
		return (false);
	return (true);
}

/* expects a string like "n", for n a float or positive integer, in [0,1000] */
bool	BitcoinExchange::parse_value(const std::string& n,
		const std::string& inputLine)
{
	double	res;

	if (n.empty() == true)
	{
		print(ERR_BAD_INPUT(inputLine));
		return (false);
	}
	if (!is_number(n))
	{
		print(ERR_BAD_INPUT(inputLine));
		return (false);
	}
	res = strtod(n.c_str(), NULL);
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

bool	BitcoinExchange::good_date_format(const std::string& date)
{
	if (date.length() != 10)
		return (false);
	if (!is_digit(date.at(0)) || !is_digit(date.at(1))
			|| !is_digit(date.at(2)) || !is_digit(date.at(3))
			|| !is_digit(date.at(5)) || !is_digit(date.at(6))
			|| !is_digit(date.at(8)) || !is_digit(date.at(9)))
		return (false);
	if (date.at(4) != '-' || date.at(7) != '-')
		return (false);
	return (true);
}

/* function expects the string in format "yyyy-mm-dd" */
bool	BitcoinExchange::parse_date(const std::string& inputLine, int& d, int& m, int& y){
	std::istringstream is(inputLine);
	char delimiter;

	if (!good_date_format(inputLine))
		return (false);
	if (is >> y >> delimiter >> m >> delimiter >> d && is.eof())
	{
		if (y < 2009 || m < 1 || m > 12 || d < 1 || d > 31)
			return (false);
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
		return (norm->tm_mday == d
				&& norm->tm_mon  == m - 1
				&& norm->tm_year == y - 1900);
	}
	return (false);
}

/* read the database file "dbname" line by line
   and fill the member var container*/
void	BitcoinExchange::read_db(const char* dbname)
{
	std::string				buf;
	std::string::size_type	pos;
	std::ifstream			ifs(dbname);

	if (ifs == false)
		throw std::runtime_error(ERR_DB);
	std::getline(ifs, buf); // jump to 2nd line 
	while(std::getline(ifs, buf))
	{
		pos = buf.find_first_of(',');
		if (pos == std::string::npos)
		{
			ifs.close();
			throw std::runtime_error(ERR_DB);
		}
		_db.insert(std::make_pair(buf.substr(0, pos) , buf.substr(pos + 1)));
	}
	ifs.close();
}

void	BitcoinExchange::print_container()
{
	MAP::iterator	it = _db.begin();
	while (it != _db.end())
	{
		std::cout << (*it).first << "," << (*it).second << std::endl;
		it++;
	}
}

/* read the input file line by line and apply the exchange rate to each line */
void	BitcoinExchange::calc(const char *input)
{
	std::ifstream	ifs(input);
	std::string		buf;

	if (ifs == false)
	{
		throw std::runtime_error(ERR_OPEN);
	}
	std::getline(ifs, buf); // jump to 2nd line
	while (std::getline(ifs, buf))
	{
		exchange_rate(buf);
	}
	ifs.close();
}

/* multiply the input value by the bitcoin exchange rate */
void	BitcoinExchange::exchange_rate(const std::string& buf)
{
	std::string::size_type	pos = buf.find_first_of('|');
	if (pos == std::string::npos)
	{
		print(ERR_BAD_INPUT(buf));
		return ;
	}
	if (buf.size() < pos + 2)
	{
		print(ERR_BAD_INPUT(buf));
		return ;
	}
	if (buf.at(pos - 1) != ' ' || buf.at(pos + 1) != ' ')
	{
		print(ERR_BAD_INPUT(buf));
		return ;
	}
	std::string				date = buf.substr(0, pos - 1);
	std::string				value = buf.substr(pos + 2);
	MAP::iterator			it = _db.find(date);
	double					result;

	/* std::cout << "date:[" << date << "] , value:[" << value << "]" << std::endl; */
	if (parse(date, value, buf) == false)
		return ;
	if (it == _db.end()) // input date does not exist in DB
	{
		it = _db.lower_bound(date); // find the lower closest date
		if (it == _db.begin()) // lower closest date does not exist
		{
			print(ERR_BAD_INPUT(buf));
			return ;
		}
		--it;
	}
	result = strtod(((*it).second).c_str(), NULL) * strtod(value.c_str(), NULL);
	if (result == HUGE_VAL)
		throw std::runtime_error(ERR_RANGE);
	std::cout << date << " => " << value << " = " << result << std::endl;
}

// parse the input file. Expected format: "date | value"
bool	BitcoinExchange::parse(const std::string& date, const std::string& value, 
		const std::string& line)
{
	int	d;
	int	m;
	int	y;

	if (parse_date(date, d, m, y) == false)
	{
		print(ERR_BAD_INPUT(line));
		return (false);
	}
	return (parse_value(value, line));
}
