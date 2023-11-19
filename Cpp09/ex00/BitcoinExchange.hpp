#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <exception>
# include <iostream>
# include <string>
# include <fstream>

# include <map>
# include <utility> // std::make_pair()
# include <stdlib.h> // atof
# include <sstream> // std::istringstream
# include <ctime> // mktime() localtime()

/* path to the database file */
# define DATABASE "./data.csv"

/* error messages */
# define ERR_OPEN "Error: could not open file."
# define ERR_STREAM "Error: failed to read file."
# define ERR_NOT_POS "Error: not a positive number."
# define ERR_TOO_BIG "Error: too large a number."
# define ERR_DATE(date) "Error: bad input => " + date 

# define MAP std::map<std::string, std::string>
# define BUFSIZE 40


void	print(const std::string& reason);
bool	parse_date(const std::string&, int&, int&, int&);
bool	parse_value(const std::string&);
bool	parse_filename(const char*);

class BitcoinExchange
{
	private:
		MAP	_db;
		void	fill_container(const char *);
		void	exchange_rate(const char*);
		bool	parse(const std::string&, const std::string&);

	public:
		~BitcoinExchange();
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator = (const BitcoinExchange &other);

		bool	read_db();
		void	print_container();
		void	calc(const char*);

};

#endif
