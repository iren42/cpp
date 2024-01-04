#include "BitcoinExchange.hpp"

//		std::cout << << std::endl;
BitcoinExchange::~BitcoinExchange()
{
	_db.clear();
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

/* expects a string like " n", for n a float or positive integer, in [0,1000] */
bool	BitcoinExchange::parse_value(const std::string& s, const std::string& line)
{
	double	res;

	(void)line;
	if (line.empty() == true)
		return (false);
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

/* function expects the string in format "yyyy-mm-dd " */
bool	BitcoinExchange::parse_date(const std::string& s, int& d, int& m, int& y){
	std::istringstream is(s);

	if (is >> y && is.get() == '-' && is >> m && is.get() == '-' && is >> d && is.eof())
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
		return (norm->tm_mday == d    &&
				norm->tm_mon  == m - 1 &&
				norm->tm_year == y - 1900);
	}
	return (false);
}

/* read the database file "dbname" line by line
   and fill the member var container*/
void	BitcoinExchange::read_db(const char* dbname)
{
	char	buf[BUFSIZE];
	std::ifstream	ifs;

	ifs.open(dbname);
	if (ifs.is_open() == false)
		throw std::runtime_error(ERR_DB);
	ifs.getline(buf, BUFSIZE - 1);
	while(ifs.eof() == false && ifs.fail() == false)
	{
		ifs.getline(buf, BUFSIZE - 1);
		if (ifs.fail() == false) // check failbit and badbit
			/* if you get a number when expect to retrieve a letter,
			   it's failbit. If a serious error happens, which disrupts the 
			   ability to read from the stream at all - it's a badbit. */
			fill_container(buf);
	}
	ifs.close();
}

/* insert a pair of date and value in the _db */
void	BitcoinExchange::fill_container(const char *s)
{
	std::string	buf = s;

	std::string::size_type	pos = buf.find_first_of(',');
	_db.insert(std::make_pair(buf.substr(0, pos) , buf.substr(pos + 1)));
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
	std::ifstream	ifs;
	char	buf[BUFSIZE];

	ifs.open(input);
	if (ifs.is_open() == false)
	{
		_db.clear();
		throw std::runtime_error(ERR_OPEN);
	}
	ifs.getline(buf, BUFSIZE - 1); /* skip 1st line */
	while(ifs.eof() == false && ifs.fail() == false)
	{
		ifs.getline(buf, BUFSIZE - 1);
		if (ifs.fail() == false)
			exchange_rate(buf);
	}
	ifs.close();
}

/* multiply the input value by the bitcoin exchange rate */
void	BitcoinExchange::exchange_rate(const char *line)
{
	std::string				buf = line;
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
	std::string				value = buf.substr(pos + 1);
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
	/* std::cout << ::atof(value.c_str()) << std::endl; */
	result = atof(((*it).second).c_str()) * atof(value.c_str());
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
