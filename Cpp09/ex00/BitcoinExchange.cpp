#include "BitcoinExchange.hpp"

//		std::cout << << std::endl;
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange Destructor called" << std::endl;
	/* print_container(); */
}

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	inputFile;
	inputFile.open(BC_FILE);
	std::cout << "file opened" << std::endl;
	init_container(inputFile);
	inputFile.close();
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	std::cout << "BitcoinExchange Copy constructor called" << std::endl;
	(*this) = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	std::cout << "BitcoinExchange Copy assignment constructor called" << std::endl;

	return (*this);
}

bool	BitcoinExchange::init_container(std::ifstream &ifs)
{
	char	buf[BUFSIZE];

	while(ifs.eof() == false)
	{
		ifs.getline(buf, BUFSIZE - 1);
		if (ifs.fail())
			return (false);
		if (ifs.eof())
		{
			std::cout << "eof reached" << std::endl;
			return (true);
		}
		/* std::cout << buf << std::endl; */
		fill_container(buf);
	}
	return (true);
}

void	BitcoinExchange::fill_container(char *s)
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

MAP::iterator	BitcoinExchange::find_by_date(std::string date)
{
 	return (_db.find(date));
}

void	BitcoinExchange::calc(char *input)
{
	std::ifstream	ifs;
	char	buf[BUFSIZE];

	ifs.open(input);
	std::cout << "input file opened" << std::endl;

/* TODO: skip 1st line */
	while(ifs.eof() == false)
	{
		ifs.getline(buf, BUFSIZE - 1);
		if (ifs.fail())
			return ;
		if (ifs.eof())
		{
			/* std::cout << "eof reached" << std::endl; */
			return ;
		}
		print_result(buf);
		/* std::cout << buf << std::endl; */
	}
	ifs.close();

}
void	BitcoinExchange::print_result(char *s)
{
	std::string				buf = s;
	std::string::size_type	pos = buf.find_first_of('|');
	std::string				date = buf.substr(0, pos - 1);
	MAP::iterator			it = _db.find(date);
	float					num_float;

	if (it == _db.end()) // exact date is not found in db
	{
		it = _db.lower_bound(date);
		--it;
		/* std::cout << "lower: " << (*it).first << std::endl; */
	}
	num_float = ::atof(((*it).second).c_str());
	std::cout << date << " => " << buf.substr(pos + 2) << " = " << num_float << std::endl;
}
