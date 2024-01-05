#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <exception>
# include <iostream>
# include <string>
# include <fstream> // std::ifstream

# include <map>
# include <utility> // std::make_pair()
# include <stdlib.h> // atof
# include <sstream> // std::istringstream
# include <ctime> // mktime() localtime()

/* path to the database file */
# define DATABASE "./data.csv"

/* error messages */
# define ERR_OPEN "Error: could not open file."
# define ERR_DB "Error: could not read database."
# define ERR_NOT_POS "Error: not a positive number."
# define ERR_TOO_BIG "Error: too large a number."
# define ERR_BAD_INPUT(erroneusline) "Error: bad input => " + erroneusline 

# define MAP std::map<std::string, std::string>


void	print(const std::string& reason);

class BitcoinExchange
{
	private:
		MAP	_db;
		
		void	exchange_rate(const std::string&);
		bool	parse(const std::string&, const std::string&,
				const std::string&);

		bool	parse_date(const std::string&, int&, int&, int&); // used in parse()
		bool	good_date_format(const std::string&);
		bool	is_digit(char); // used in good_date_format()
		bool	parse_value(const std::string&, const std::string&); // used in parse()
		bool	is_number(const std::string& line); // used in parse_value()


	public:
		~BitcoinExchange();
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator = (const BitcoinExchange &other);

		void	read_db(const char*);
		void	print_container();
		void	calc(const char*);

};

#endif
