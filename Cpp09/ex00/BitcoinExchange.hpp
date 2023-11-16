#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <exception>
# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <utility>
# include <stdlib.h>

/* path to the database file */
# define BC_FILE "./data.csv"
/* error messages */
//# define DEBUG
# define ERR_OPEN "could not open file"

# define MAP std::map<std::string, std::string>
# define BUFSIZE 40


class BitcoinExchange
{
	private:
		MAP	_db;

	public:
		~BitcoinExchange();
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator = (const BitcoinExchange &other);

		bool	init_container(std::ifstream&);
		void	fill_container(char *);
		void	print_container();
		MAP::iterator	find_by_date(std::string);
		void	calc(char*);
		void	print_result(char*);

};

#endif
