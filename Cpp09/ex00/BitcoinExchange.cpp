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

/* read the database file line by line */
bool	BitcoinExchange::read_db()
{
	char	buf[BUFSIZE];
	std::ifstream	ifs;

	ifs.open(DATABASE);
	if (ifs.is_open() == false)

	ifs.getline(buf, BUFSIZE - 1);
	while(ifs.eof() == false && ifs.fail() == false)
	{
		ifs.getline(buf, BUFSIZE - 1);
		if (ifs.fail() == false)
			fill_container(buf);
	}
	ifs.close();
	return (true);
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
	std::string				date = buf.substr(0, pos - 1);
	std::string				value = buf.substr(pos + 2);
	MAP::iterator			it = _db.find(date);
	double					result;

	if (parse(date, value) == false)
		return ;
	if (it == _db.end()) // input date does not exist in DB
	{
		it = _db.lower_bound(date); // find the lower closest date
		if (it == _db.begin()) // lower closest date does not exist
		{
			print(ERR_DATE(date));
			return ;
		}
		--it;
	}
	/* std::cout << ::atof(value.c_str()) << std::endl; */
	result = atof(((*it).second).c_str()) * atof(value.c_str());
	std::cout << date << " => " << value << " = " << result << std::endl;
}

bool	BitcoinExchange::parse(const std::string& date, const std::string& value)
{
	int	d;
	int	m;
	int	y;

	if (parse_date(date, d, m, y) == false)
	{
		print(ERR_DATE(date));
		return (false);
	}
	return (parse_value(value));
}
